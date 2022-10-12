#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QDate>
#include <QLabel>
#include <QDateTimeEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QList>
#include <QTextFrame>
#include <QTextFrameFormat>
#include <QTextCharFormat>
#include <QTextTableCell>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void setYear(QDate year);
    void setMonth(int month);
    void setFontSize(int _size);


private:
    void InsertCalendar();

private:
    QLabel *_dateLabel;
    QComboBox *_monthCombo;
    int _frontSize;
    QDate _dateSelect;
    QTextBrowser *_browserText;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
