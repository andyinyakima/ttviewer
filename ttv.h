#ifndef TTV_H
#define TTV_H

#include <QMainWindow>
#include <QProcess>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFont>
#include <QDesktopWidget>
#include <QRect>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class ttv;
}

class ttv : public QMainWindow
{
    Q_OBJECT

public:
    bool redflag = false;

    int i;
    int cnt;
    int num;
    int sidcnt;
    int posx;
    int posy;
    int wide;
    int high;
    int titleSpace;
    int desktopwidth;
    int desktopheight;
    int num_of_streams;
    int rows;
    int viewsPerRow;

    QDesktopWidget desktop;

    QString homepath;

    QStringList streamid;
    QStringList nameid;


    explicit ttv(QWidget *parent = 0);
    ~ttv();
private slots:

    void MonitorLUFs();

    void ShowFFplays();

    void ShowMPVs();

    void ShowQVideos();

    void listStreams();

    void on_ffplay_pushButton_clicked();

    void on_setMPVs_pushButton_clicked();

    void on_pushButton_clicked();

    void on_rows_wanted_spinBox_valueChanged(int arg1);

private:
    Ui::ttv *ui;
};

#endif // TTV_H
