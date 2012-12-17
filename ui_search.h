/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created: Sun Dec 16 15:58:50 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_search
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *ISBN;
    QLineEdit *bookName;
    QLineEdit *authorName;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QLineEdit *flei;
    QTableWidget *tableWidget;

    void setupUi(QDialog *search)
    {
        if (search->objectName().isEmpty())
            search->setObjectName(QString::fromUtf8("search"));
        search->resize(739, 403);
        gridLayout = new QGridLayout(search);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(search);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 4, 1, 1);

        ISBN = new QLineEdit(search);
        ISBN->setObjectName(QString::fromUtf8("ISBN"));

        gridLayout_2->addWidget(ISBN, 0, 5, 1, 1);

        bookName = new QLineEdit(search);
        bookName->setObjectName(QString::fromUtf8("bookName"));

        gridLayout_2->addWidget(bookName, 0, 1, 1, 1);

        authorName = new QLineEdit(search);
        authorName->setObjectName(QString::fromUtf8("authorName"));

        gridLayout_2->addWidget(authorName, 0, 3, 1, 1);

        pushButton = new QPushButton(search);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 4, 1, 1);

        label_2 = new QLabel(search);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        label = new QLabel(search);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 6, 1, 1);

        label_4 = new QLabel(search);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        flei = new QLineEdit(search);
        flei->setObjectName(QString::fromUtf8("flei"));

        gridLayout_2->addWidget(flei, 1, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 3);

        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        tableWidget = new QTableWidget(search);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 3);
        gridLayout->setRowStretch(1, 10);

        retranslateUi(search);

        QMetaObject::connectSlotsByName(search);
    } // setupUi

    void retranslateUi(QDialog *search)
    {
        search->setWindowTitle(QApplication::translate("search", "\346\220\234\347\264\242", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("search", "        ISBN", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("search", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("search", "         \344\275\234\350\200\205       ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("search", "         \344\271\246\345\220\215            ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("search", "       \345\210\206\347\261\273\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("search", "ISBN", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("search", "\344\271\246\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("search", "\344\275\234\350\200\205", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("search", "\345\207\272\347\211\210\347\244\276", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("search", "\344\273\267\346\240\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("search", "\345\202\250\345\255\230\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("search", "\345\210\206\347\261\273\345\217\267", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class search: public Ui_search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
