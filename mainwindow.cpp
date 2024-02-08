/*
 * @file
 * @brief Файл реализации класса MainWindow
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    settings = new QSettings(this);
    loadSettings();



}

MainWindow::~MainWindow()
{
    CloseFile();
    saveSettings();
    delete ui;

}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName;
    QString fileNameNew;
    int curindex;
    fileName = QFileDialog::getOpenFileName(this,
    tr("Open File"), "", tr("Any Files (*.*)"));
    fileNameNew = fileName + "new";

    if (!fileName.isNull())
    {
        QFile::copy(fileName, fileNameNew);

        file = fileName;

        qtabForms.append(new QTabForm());


        int i = ui->tabWidget->count();
        if (i == 0) {
            ui->tabWidget->addTab(qtabForms[0], fileName);
            dtModels.append(new ConsuppliersDataTableModel());
            dtModels[0]->readData(fileNameNew);
            dtModels[0]->setFile(fileName);
            qtabForms[0]->setTableModel(dtModels[0]);
        }
        else {
        ui->tabWidget->addTab(qtabForms[i], fileName);
        dtModels.append(new ConsuppliersDataTableModel());
        dtModels[i]->readData(fileNameNew);
        dtModels[i]->setFile(fileName);
        qtabForms[i]->setTableModel(dtModels[i]);
        ui->tabWidget->setCurrentIndex(i);
        }
    }
}


void MainWindow::on_actionNew_triggered()
{
    int i = ui->tabWidget->count();
    if (i == 0) {
        qtabForms.append(new QTabForm());
        ui->tabWidget->addTab(qtabForms[0], tr("New"));
        dtModels.append(new ConsuppliersDataTableModel());
        dtModels[0]->appendLine();
        qtabForms[0]->setTableModel(dtModels[0]);
    }
    else {
        dtModels.append(new ConsuppliersDataTableModel());
        qtabForms[i] = new QTabForm();
        dtModels[i]->appendLine();
    }


}


void MainWindow::on_actionSave_triggered()
{
    int curindex = ui->tabWidget->currentIndex();
    QString file = dtModels[curindex]->getFile();
    QString fileNew = file + "new";

    dtModels[curindex]->saveFile(fileNew);
    QFile::remove(file);
    QFile::copy(fileNew, file);
}


void MainWindow::CloseFile()
{
    if (dtModels[ui->tabWidget->currentIndex()]->getEdited()) {
        if (AskSave()) {
            on_actionSave_triggered();
            return;
        }
    }


    int curindex = ui->tabWidget->currentIndex();

    QString fileNew = dtModels[curindex]->getFile() + "new";
    QFile::remove(fileNew);

    dtModels.remove(curindex);
    qtabForms.remove(curindex);
    ui->tabWidget->removeTab(curindex);


}

void MainWindow::Reboot()
{
    QString program = QApplication::applicationFilePath();
    QStringList arguments = QApplication::arguments();
    QString workingDirectory = QDir::currentPath();
    QProcess::startDetached(program, arguments, workingDirectory);
    QApplication::exit();
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{

    int curindex = ui->tabWidget->currentIndex();
    dtModels[curindex]->clearAll();

    CloseFile();
}


bool MainWindow::AskSave()
{
    if(QMessageBox::question(this, tr("Save file?"), tr("Save file before closing?")) == QMessageBox::Yes)
        return true;
    else
        return false;
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileNameNew = QFileDialog::getSaveFileName(this,
    tr("Save File"), "", tr("Any Files (*.*)"));
    int curindex = ui->tabWidget->currentIndex();
    QString fileNameOld = dtModels[curindex]->getFile();
    dtModels[curindex]->saveFile(fileNameNew);

    QFile::remove(fileNameOld);
    qtabForms[curindex]->setTableModel(dtModels[curindex]);

}

void MainWindow::ChangeTranslator(QString lang)
{
    QApplication::removeTranslator(translator);
    translator = new QTranslator(this);
    translator->load(QApplication::applicationName() + "/translation" + "_" + lang);
    QApplication::installTranslator(translator);
}

void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        setWindowTitle(tr("KRP"));
        ui->menu->setTitle(tr("File"));
        ui->menu_2->setTitle(tr("About"));
        ui->menuLanguage->setTitle(tr("Language"));
    }
}


void MainWindow::on_actionRussian_triggered()
{
    ChangeTranslator("ru_RU");
}


void MainWindow::on_actionEnglish_triggered()
{
    ChangeTranslator("en_US");
}


void MainWindow::on_actionGerman_triggered()
{
    ChangeTranslator("de_GE");

}

void MainWindow::saveSettings()
{
    settings->setValue("language", language);
    settings->setValue("geometry", geometry());
}


void MainWindow::loadSettings()
{
    ChangeTranslator(settings->value("language", "en_US").toString());
    setGeometry(settings->value("geometry", QRect(803, 803, 572, 572)).toRect());

}

void MainWindow::on_actionChoose_Language_triggered()
{
    QStringList languages;
    languages << "Russian" << "English" << "German";
    QString lang = QInputDialog::getItem(NULL, tr("Select Language"), tr("Language"), languages);
    if (lang == "Russian")
        ChangeTranslator("ru_RU");
    if (lang == "English")
                ChangeTranslator("en_US");
    if (lang == "German")
                ChangeTranslator("de_GE");

    Reboot();
}

void MainWindow::aboutProgram()
{
    QMessageBox about;
    about.setText("Program is done by");
    about.setInformativeText("student Safin Ralif of ICTMS-2-8");
    about.setIcon(QMessageBox::NoIcon);
    about.setDefaultButton(QMessageBox::Ok);
    about.exec();

}


void MainWindow::on_actionAbout_Program_triggered()
{
    aboutProgram();
}

