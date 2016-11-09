#include "orb_stash_table.h"
#include "ui_orb_stash_table.h"

#include "ffrk_abilities.h"

/**
 * Constructor
 */
orb_stash_table::orb_stash_table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orb_stash_table),
    _settings("Tibonium Inc,", "FFRK Orb Stash"),
    _max_row(13),
    _max_col(6),
    _listener(0),
    _labels(_max_row)
{
    ui->setupUi(this) ;
    _stash = new int*[_max_row] ;
    for(int i=0; i<_max_row; ++i) {
        _stash[i] = new int[_max_col] ;
    }

    _labels[POWER]     = "Power" ;
    _labels[WHITE]     = "White" ;
    _labels[BLACK]     = "Black" ;
    _labels[SUMMON]    = "Summon" ;
    _labels[NON_ELEM]  = "Non-Elem" ;
    _labels[FIRE]      = "Fire" ;
    _labels[ICE]       = "Ice" ;
    _labels[LIGHTNING] = "Lightning" ;
    _labels[EARTH]     = "Earth" ;
    _labels[WIND]      = "Wind" ;
    _labels[HOLY]      = "Holy" ;
    _labels[DARK]      = "Dark" ;
    _labels[BLUE]      = "Blue" ;

    setup_table() ;
    import_stash() ;
}

/**
 * Destructor
 */
orb_stash_table::~orb_stash_table()
{
    save_stash() ;
    for(int i=0; i<_max_row; ++i) {
        delete _stash[i] ;
    }
    delete _stash ;
    delete ui ;
}

/**
 * Saves the position and size for when shown again
 */
void orb_stash_table::closeEvent(QCloseEvent *e)
{
    _settings.setValue("position", pos()) ;
    _settings.setValue("size", size()) ;
    e->accept() ;
}

/**
 * Saves the table data
 */
void orb_stash_table::save_stash()
{
    std::fstream fi("orb_stash", std::fstream::out) ;
    if( !fi.good() ) {
        QMessageBox msg ;
        msg.setWindowTitle("Error loading Orb Stash data") ;
        msg.setText( std::strerror(errno) ) ;
        msg.exec() ;
        return ;
    }
    std::string line ;
    for(int i=0; i<_max_row; ++i) {
        line = _labels[i] ;
        line += "," ;
        for(int j=0; j<_max_col; ++j) {
            std::stringstream iss ;
            iss << _stash[i][j] ;
            line += iss.str() ;
            if( j < _max_col ) line += "," ;
        }
        line += '\n' ;
        fi << line ;
    }
    fi.close() ;
}

/**
 * Makes the table visible
 */
void orb_stash_table::unhide()
{
    if( !isVisible() ) {
        if( _settings.contains("position") )
            move( _settings.value("position").toPoint() ) ;
        if( _settings.contains("size") )
            resize( _settings.value("size").toSize() ) ;
        show() ;
        raise() ;
        activateWindow() ;
    }
}

/**
 * Setup the table for use
 */
void orb_stash_table::setup_table()
{
    for(int i=0; i<_max_row; ++i) {
        ui->stash_table->setItem(i, MINOR, new QTableWidgetItem() ) ;
        ui->stash_table->setItem(i, LESSER, new QTableWidgetItem() ) ;
        ui->stash_table->setItem(i, NORMAL, new QTableWidgetItem() ) ;
        ui->stash_table->setItem(i, GREATER, new QTableWidgetItem() ) ;
        ui->stash_table->setItem(i, MAJOR, new QTableWidgetItem() ) ;
        ui->stash_table->setItem(i, CRYSTAL, new QTableWidgetItem() ) ;
    }
}

/**
 * Imports all orb data from the flat file: orb_stash
 */
void orb_stash_table::import_stash()
{
    std::fstream fi("orb_stash", std::fstream::in) ;
    if( !fi.good() ) {
//        QMessageBox msg ;
//        msg.setWindowTitle("Error loading Orb Stash data") ;
//        msg.setText( std::strerror(errno) ) ;
//        msg.exec() ;
        return ;
    }
    while( true ) {
        std::string line, tmp ;
        std::getline(fi, line) ;
        if( fi.eof() ) break ;
        std::stringstream iss ;
        iss << line ;
        // First determine the type
        std::getline(iss, tmp, ',') ;
        if( iss.eof() ) break ;
        OrbType t = find_type( tmp ) ;
        // skip this line if the type is not one of the pre-defined ones
        if( t == UNKNOWN ) continue ;

        // Extract the numbers and store them
        std::getline(iss, tmp, ',') ;
        _stash[t][MINOR] = std::atoi(tmp.c_str()) ;
        std::getline(iss, tmp, ',') ;
        _stash[t][LESSER] = std::atoi(tmp.c_str()) ;
        std::getline(iss, tmp, ',') ;
        _stash[t][NORMAL] = std::atoi(tmp.c_str()) ;
        std::getline(iss, tmp, ',') ;
        _stash[t][GREATER] = std::atoi(tmp.c_str()) ;
        std::getline(iss, tmp, ',') ;
        _stash[t][MAJOR] = std::atoi(tmp.c_str()) ;
        std::getline(iss, tmp, ',') ;
        _stash[t][CRYSTAL] = std::atoi(tmp.c_str()) ;
    }
    for(int i=0; i<_max_row; ++i) {
        for(int j=0; j<_max_col; ++j) {
            int value = _stash[i][j] ;
            if( value == 0 ) {
                ui->stash_table->item(i, j)->setText( QString() ) ;
            } else {
                ui->stash_table->item(i, j)->setText( QString::number(_stash[i][j]) ) ;
            }
        }
    }
    fi.close() ;
}

/**
 * Returns the type of orb
 */
OrbType orb_stash_table::find_type(std::string type)
{
    if( type == _labels[POWER] ) {
        return POWER ;
    } else
    if( type == _labels[WHITE] ) {
        return WHITE ;
    } else
    if( type == _labels[BLACK] ) {
        return BLACK ;
    } else
    if( type == _labels[SUMMON] ) {
        return SUMMON ;
    } else
    if( type == _labels[NON_ELEM] ) {
        return NON_ELEM ;
    } else
    if( type == _labels[FIRE] ) {
        return FIRE ;
    } else
    if( type == _labels[ICE] ) {
        return ICE ;
    } else
    if( type == _labels[LIGHTNING] ) {
        return LIGHTNING ;
    } else
    if( type == _labels[EARTH] ) {
        return EARTH ;
    } else
    if( type == _labels[WIND] ) {
        return WIND ;
    } else
    if( type == _labels[HOLY] ) {
        return HOLY ;
    } else
    if( type == _labels[DARK] ) {
        return DARK ;
    } else
    if( type == _labels[BLUE] ) {
        return BLUE ;
    }
    return UNKNOWN ;
}

/**
 * Updates the values when changed
 */
void orb_stash_table::on_stash_table_cellChanged(int row, int column)
{
    int value = ui->stash_table->item(row, column)->text().toInt() ;
    if( value <= 0 ) {
        value = 0 ;
        ui->stash_table->item(row, column)->setText( QString() ) ;
    } else {
        ui->stash_table->item(row, column)->setText( QString::number(value) ) ;
    }
    _stash[row][column] = value ;
    if( _listener ) {
        _listener->update_orb_cell(row, column) ;
    }
}
