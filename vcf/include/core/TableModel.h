/**
*Copyright (c) 2000-2001, Jim Crafton
*All rights reserved.
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions
*are met:
*	Redistributions of source code must retain the above copyright
*	notice, this list of conditions and the following disclaimer.
*
*	Redistributions in binary form must reproduce the above copyright
*	notice, this list of conditions and the following disclaimer in 
*	the documentation and/or other materials provided with the distribution.
*
*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
*AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
*OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
*PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*NB: This software will not save the world.
*/

/* Generated by Together */


#ifndef TABLEMODEL_H
#define TABLEMODEL_H


namespace VCF{

class TableCellItem;

class TableModelListener;

typedef Enumerator<TableCellItem*> TableRowItemEnumerator;

#define TABLEMODEL_CLASSID     "BCA97CD1-6567-11d4-8EFF-00207811CFAB"

/**
*
*/
class APPKIT_API TableModel : public VCF::Model {    
public:
	BEGIN_ABSTRACT_CLASSINFO(TableModel, "VCF::TableModel", "VCF::Model", TABLEMODEL_CLASSID )
	EVENT( "VCF::TableModelEventHandler", "VCF::TableModelEvent", "TableCellAdded" )
	EVENT( "VCF::TableModelEventHandler", "VCF::TableModelEvent", "TableCellDeleted" )
	EVENT( "VCF::TableModelEventHandler", "VCF::TableModelEvent", "TableRowAdded" )
	EVENT( "VCF::TableModelEventHandler", "VCF::TableModelEvent", "TableRowDeleted" )
	EVENT( "VCF::TableModelEventHandler", "VCF::TableModelEvent", "TableColumnAdded" )
	EVENT( "VCF::TableModelEventHandler", "VCF::TableModelEvent", "TableColumnDeleted" )
	END_CLASSINFO(TableModel)

	virtual ~TableModel(){};    

	virtual void addTableCellAddedHandler( EventHandler* handler ) = 0;
	
	virtual void removeTableCellAddedHandler( EventHandler* handler ) = 0;

	virtual void addTableCellDeletedHandler( EventHandler* handler ) = 0;
	
	virtual void removeTableCellDeletedHandler( EventHandler* handler ) = 0;    

	virtual void addTableRowAddedHandler( EventHandler* handler ) = 0;

	virtual void removeTableRowAddedHandler( EventHandler* handler ) = 0;

	virtual void addTableRowDeletedHandler( EventHandler* handler ) = 0;

	virtual void removeTableRowDeletedHandler( EventHandler* handler ) = 0;

	virtual void addTableColumnAddedHandler( EventHandler* handler ) = 0;

	virtual void removeTableColumnAddedHandler( EventHandler* handler ) = 0;

	virtual void addTableColumnDeletedHandler( EventHandler* handler ) = 0;

	virtual void removeTableColumnDeletedHandler( EventHandler* handler ) = 0;

    virtual void addRow() = 0;

	virtual void insertRow( const uint32& afterRow ) = 0;

	virtual void deleteRow( const uint32& row ) = 0;

    virtual void addColumn() = 0;

	virtual void insertColumn( const uint32& afterColumn ) = 0;

	virtual void deleteColumn( const uint32& column ) = 0;

	virtual bool isCellEditable( const uint32& row, const uint32& column ) = 0;

	virtual TableCellItem* getItem( const uint32& row, const uint32& column ) = 0;
	
	virtual uint32 getRowCount() = 0;

	virtual uint32 getColumnCount() = 0;
	
	virtual TableRowItemEnumerator* getRowItemEnumerator( const uint32& row ) = 0;

	/**
	*this is overriden to provide TableModels derivations
	*control over what kind of item get created 
	*at any cell in the table.
	*@param uint32 - the row being created
	*/
	virtual void createCell( const uint32& row, const uint32& column, TableCellItem** createdCell ) = 0;
};

};
#endif //TABLEMODEL_H