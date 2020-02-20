/*
 * Copyright (C) 2020 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KIMAGEANNOTATOR_SCALEDSIZEPROVIDER_H
#define KIMAGEANNOTATOR_SCALEDSIZEPROVIDER_H

#include <QGuiApplication>
#include <QCoreApplication>
#include <QApplication>
#include <QDesktopWidget>

namespace kImageAnnotator {

class ScaledSizeProvider
{
public:
	static QSize getScaledSize(const QSize &size);

private:
	static qreal getXScaleFactor();
	static qreal getYScaleFactor();
	static qreal getReferenceDpiValue();
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_SCALEDSIZEPROVIDER_H
