/*  FrameEllipse.h
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

#ifndef libglabels_FrameEllipse_h
#define libglabels_FrameEllipse_h

#include "Frame.h"


namespace libglabels
{

	class FrameEllipse : public Frame
	{
	public:
		FrameEllipse( double  w,
			      double  h,
			      double  waste,
			      QString id = "0" )
			: mW(w), mH(h), mWaste(waste), Frame(id)
		{
			mPath.addEllipse( 0, 0, mW, mH );
		}

		FrameEllipse( const FrameEllipse &other )
			: mW(other.mW), mH(other.mH), mWaste(other.mWaste), mPath(other.mPath), Frame(other)
		{
		}

		Frame *dup() const { return new FrameEllipse( *this ); }

		inline double waste() const { return mWaste; }

		double w() const { return mW; }
		double h() const { return mH; }

		const QString sizeDescription( const Units *units ) const;
		bool isSimilarTo( Frame *other ) const;

		const QPainterPath &path() const { return mPath; }


	private:
		double mW;
		double mH;
		double mWaste;

		QPainterPath mPath;

	};

}

#endif // libglabels_FrameEllipse_h
