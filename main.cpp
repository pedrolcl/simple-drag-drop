/**
 * Copyright (c) 2023, Pedro López-Cabanillas
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <QApplication>
#include <QListView>

#include "dragdropitemmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DragDropItemModel model1;

    QStandardItem item1(u"Hello"_s);
    item1.setData(u"Good morning"_s, Qt::UserRole);
    model1.appendRow(&item1);

    QStandardItem item2(u"Cruel"_s);
    item2.setData(u"\"Goodbye Cruel World\" is a song by Pink Floyd"_s, Qt::UserRole);
    model1.appendRow(&item2);

    QStandardItem item3(u"World"_s);
    item3.setData(u"Earth is the planet where humans live"_s, Qt::UserRole);
    model1.appendRow(&item3);

    DragDropItemModel model2;

    QListView view1;
    QListView view2;

    view1.setModel(&model1);
    view1.setDragEnabled(true);
    view1.setWindowTitle(u"Drag these items"_s);

    view2.setModel(&model2);
    view2.setAcceptDrops(true);
    view2.setWindowTitle(u"Drop items here"_s);

    view1.show();
    view2.show();

    return a.exec();
}
