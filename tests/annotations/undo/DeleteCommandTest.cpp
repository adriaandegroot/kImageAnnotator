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

#include "DeleteCommandTest.h"

#include "tests/mocks/MockDefaultParameters.h"

void DeleteCommandTest::TestRedo_Should_ApplyOperation()
{
	MockAnnotationAreaParameters p;
	AnnotationArea annotationArea(&p.config, &p.settingsProvider, &p.scaler, &p.zoomValueProvider);
	auto properties = PropertiesPtr(new AnnotationProperties(Qt::red, 1));
	QLineF line(10, 10, 20, 20);
	AnnotationLine item(line.p1(), properties);
	item.addPoint(line.p2(), false);
	annotationArea.addAnnotationItem(&item);
	QCOMPARE(annotationArea.items().contains(&item), true);
	QList<AbstractAnnotationItem *> items = { &item };
	DeleteCommand deleteCommand(items, &annotationArea);

	deleteCommand.redo();

	QCOMPARE(annotationArea.items().contains(&item), false);
}

void DeleteCommandTest::TestUndo_Should_UndoOperation()
{
	MockAnnotationAreaParameters p;
	AnnotationArea annotationArea(&p.config, &p.settingsProvider, &p.scaler, &p.zoomValueProvider);
	auto properties = PropertiesPtr(new AnnotationProperties(Qt::red, 1));
	QLineF line(10, 10, 20, 20);
	AnnotationLine item(line.p1(), properties);
	item.addPoint(line.p2(), false);
	annotationArea.addAnnotationItem(&item);
	QList<AbstractAnnotationItem *> items = { &item };
	DeleteCommand deleteCommand(items, &annotationArea);
	deleteCommand.redo();
	QCOMPARE(annotationArea.items().contains(&item), false);

	deleteCommand.undo();

	QCOMPARE(annotationArea.items().contains(&item), true);
}

QTEST_MAIN(DeleteCommandTest);
