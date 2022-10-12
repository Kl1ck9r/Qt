#include "mainwindow.h"

#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _dateSelect=QDate::currentDate(); // set currentDate;
    _frontSize=10;

    QWidget *_setCentralWidget=new QWidget;


    _dateLabel=new QLabel(tr("Date:"));

    _monthCombo=new QComboBox;

    for(int month=0;month<11;month++)
        _monthCombo->addItem(QLocale::system().monthName(month));

    QDateTimeEdit *_yearEdit=new QDateTimeEdit;

    _yearEdit->setDisplayFormat("yyyy");
    _yearEdit->setDateRange(QDate(1753,1,1),QDate(8000,1,1)); // setDateRange = function for set min and max date with one call


    _monthCombo->setCurrentIndex(_dateSelect.month()-1);

    _yearEdit->setDate(_dateSelect);


    QLabel *_fontSize_label=new QLabel(tr("Font size: "));
    QSpinBox *_fontSizeSpinBox=new QSpinBox;
    _fontSizeSpinBox=new QSpinBox;
    _fontSizeSpinBox->setRange(1,64); // 1(min) and 2(max)

    _browserText=new QTextBrowser;

     InsertCalendar();


     connect(_monthCombo,SIGNAL(activated(int)),this,SLOT(setMonth(int)));

     connect(_yearEdit,SIGNAL(dateChanged(QDate)),this,SLOT(setYear(QDate)));

     connect(_fontSizeSpinBox,SIGNAL(valueChanged(int)),this,SLOT(setFontSize(int)));

     _fontSizeSpinBox->setValue(10);



     QHBoxLayout *_contrLayout=new QHBoxLayout;
     _contrLayout->addWidget(_dateLabel);
     _contrLayout->addWidget(_monthCombo);
     _contrLayout->addWidget(_yearEdit);
  //   _сontrLayout->addSpacing(24); // for create empty cell
     _contrLayout->addWidget(_fontSize_label);
     _contrLayout->addWidget(_fontSizeSpinBox);

     QVBoxLayout *_centraLayout=new QVBoxLayout;
     _centraLayout->addLayout(_contrLayout);

     _centraLayout->addWidget(_browserText);

     _setCentralWidget->setLayout(_centraLayout);

     setCentralWidget(_setCentralWidget);




}

void MainWindow::setYear(QDate year)
{
    _dateSelect=QDate(year.year(),_dateSelect.month(),_dateSelect.day());
    InsertCalendar();

}

void MainWindow::InsertCalendar()
{

    _browserText->clear();

    QTextCursor _cursor=_browserText->textCursor(); // QtextCursor let me redaction documents and them struct

    _cursor.beginEditBlock();

    QDate t_date(_dateSelect.year(),_dateSelect.month(),1);

    QTextTableFormat _tableFormat;
    _tableFormat.setAlignment(Qt::AlignCenter);
    _tableFormat.setBackground(QColor("#e0e0e0"));
    _tableFormat.setCellPadding(2); // Returns the padding of the table. Describes
    // the distance between the border of a cell and its contents.

    _tableFormat.setCellPadding(2); // Returns the spacing between table cells.
    //  Describes the spacing between adjacent cells.

    QVector<QTextLength> _contraints;
    _contraints<<QTextLength(QTextLength::PercentageLength,14)
               <<QTextLength(QTextLength::PercentageLength,14)
               <<QTextLength(QTextLength::PercentageLength,14)
               <<QTextLength(QTextLength::PercentageLength,14)
               <<QTextLength(QTextLength::PercentageLength,14)
               <<QTextLength(QTextLength::PercentageLength,14)
               <<QTextLength(QTextLength::PercentageLength,14);

    _tableFormat.setColumnWidthConstraints(_contraints);

    QTextTable * _table=_cursor.insertTable(1,7,_tableFormat);

    QTextFrame *_frame = _cursor.currentFrame();

    QTextFrameFormat _frameFormat =_frame->frameFormat();


    _frameFormat.setBorder(1);

    _frame->setFrameFormat(_frameFormat);



    QTextCharFormat _format=_cursor.charFormat();
   _format.setFontPointSize(_frontSize);


   QTextCharFormat t_boldFormat=_format;
   t_boldFormat.setFontWeight(QFont::Bold);


   QTextCharFormat t_highliFormat=t_boldFormat;
   t_highliFormat.setBackground(Qt::yellow);


   for(int _weekDay=1;_weekDay<=7;_weekDay++){
       QTextTableCell cell=_table->cellAt(0,_weekDay-1);

       QTextCursor _cellCursor=cell.firstCursorPosition();
       _cellCursor.insertText(QLocale::system().dayName(_weekDay),t_boldFormat);

   }

    _table->insertRows(_table->rows(),1);


    setWindowTitle(tr("Calendar for %1 %2").arg(QLocale::system().monthName(_dateSelect.month())
                                          ).arg(_dateSelect.year()));

}

void MainWindow::setMonth(int month)
{
    _dateSelect=QDate(_dateSelect.year(),month+1,_dateSelect.day());
    InsertCalendar();
}

void MainWindow::setFontSize(int _size)
{
    _frontSize=_size;
    InsertCalendar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

