/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
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

#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <KColorCombo>

class ColorPicker : public QWidget
{
    Q_OBJECT
public:
    explicit ColorPicker(const QIcon& icon);
    ~ColorPicker();
    void setColor(const QColor& color);

signals:
    void colorSelected(const QColor& color);

private:
    QHBoxLayout*           mLayout;
    QLabel*                mLabel;
    QColor                 mSelectedColor;
    KColorCombo*           mColorCombo;

    void initGui(const QIcon& icon);

private slots:
    void colorActivated(const QColor& color);
};

#endif // COLORPICKER_H