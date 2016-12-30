/*  TextNode.cpp
 *
 *  Copyright (C) 2013  Jim Evins <evins@snaught.com>
 *
 *  This file is part of gLabels-qt.
 *
 *  gLabels-qt is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  gLabels-qt is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with gLabels-qt.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "TextNode.h"


///
/// Default Constructor
///
TextNode::TextNode()
	: mIsField(false), mData("")
{
}


///
/// Constructor from Data
///
TextNode::TextNode( bool isField, const QString &data )
	: mIsField(isField), mData(data)
{
}


///
/// == Operator
///
bool TextNode::operator==( const TextNode& other )
{
	return ( (mIsField == other.mIsField) &&
		 (mData    == other.mData) );
}


///
/// != Operator
///
bool TextNode::operator!=( const TextNode& other )
{
	return ( (mIsField != other.mIsField) ||
		 (mData    != other.mData) );
}


///
/// isField? Property Getter
///
bool TextNode::isField( void ) const
{
	return mIsField;
}


///
/// Data Property Getter
///
const QString& TextNode::data( void ) const
{
	return mData;
}


///
/// Get text, expand if necessary
///
QString TextNode::text( merge::Record* record ) const
{
	if ( mIsField )
	{
		if ( !record )
		{
			return QString("${%1}").arg( mData );
		}
		else
		{
			if ( record->contains( mData ) )
			{
				return (*record)[ mData ];
			}
			else
			{
				return "";
			}
		}
	}
	else
	{
		return mData;
	}
}


///
/// Is it an empty field
///
bool TextNode::isEmptyField( merge::Record* record ) const
{
	if ( record && mIsField )
	{
		if ( record->contains( mData ) )
		{
			return ( (*record)[mData].isEmpty() );
		}
	}

	return false;
}
