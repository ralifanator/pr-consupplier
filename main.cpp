#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load(QApplication::applicationName() + "_" + QLocale::system().name());
    a.installTranslator(&translator);
//    const QStringList uiLanguages = QLocale::system().uiLanguages();
//    for (const QString &locale : uiLanguages) {
//        const QString baseName = "kurs_" + QLocale(locale).name();
//        if (translator.load(":/i18n/" + baseName)) {
//            a.installTranslator(&translator);
//            break;
//        }
//    }

    QApplication::setOrganizationName("RalifSafin");
    QApplication::setApplicationName("Kursovaya");

    MainWindow w;
    w.show();
    return a.exec();
}
