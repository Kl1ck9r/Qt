#ifndef CALENDAR_H
#define CALENDAR_H

#include <QtWidgets>
#include <QMainWindow>

class Calendar : public QWidget
{
    Q_OBJECT

public:
    Calendar(QWidget *parent = nullptr);
    ~Calendar(){}

public slots:
    void setFormatString(const QString &formatString);

private:
    void createSpinBox();
    void createDateTimeEdits();
    void createDoubleSpinBox();


    QDateTimeEdit *meetingEdit;
    QDoubleSpinBox *doubleSpinBox;
    QGroupBox *spinBoxGroup;
    QGroupBox *editsGroup;
    QGroupBox *doubleSpinBoxes;
    QLabel *meetingLabel;
};
#endif // CALENDAR_H
