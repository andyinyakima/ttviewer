#include "ttv.h"
#include "ui_ttv.h"

ttv::ttv(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ttv)
{
    ui->setupUi(this);

    listStreams();
}



ttv::~ttv()
{


    delete ui;
}

void ttv::listStreams()
{
    // list streams will show what is suppose to be streaming from file "tts.strm"
    // if ttstreamer stops "tts.strm" will be cleared
     homepath = QDir::homePath();

     int len;
     int pos;

     QString  line;
     QString  space =" ";
     QString  stream;
     QString  name;

     streamid.clear();
     nameid.clear();
     sidcnt =0;
     desktopwidth = desktop.geometry().width();
     ui->width_lineEdit->insert(QString::number(desktopwidth));

     desktopheight = desktop.geometry().height();
     ui->height_lineEdit->insert(QString::number(desktopheight));

     //  QString homepath = QDir::homePath();
         homepath.append("/tts.strm");
         QFile filein(homepath);
         filein.open(QIODevice::ReadOnly | QIODevice::Text);

          QTextStream streamin(&filein);

         while(!filein.atEnd())
         {
             line=filein.readLine(0);
             ui->textBrowser->insertPlainText(line);
             stream = line;
             pos = line.indexOf(space);
             stream.truncate(pos);
             streamid.append(stream);
             line.remove(0,pos+3);
             name =line;
            // name.remove(0,24);
             len=name.length();
             name.truncate(len-1);
             nameid.append(name);

             sidcnt++;


         }
/*
         for(cnt=0;cnt<sidcnt;cnt++)
         {
             ui->textBrowser->append(streamid.at(cnt));
             ui->textBrowser->append(nameid.at(cnt));
         }
*/
         if(sidcnt==0)
         {
             statusBar()->showMessage(tr("tts.strm is empty.... see if ttstreamer is running"));
         }

         num_of_streams=sidcnt-1;
         ui->num_serv_lineEdit->insert(QString::number(num_of_streams));
         wide=desktopwidth/num_of_streams;
         high=wide;
         ui->width_spinBox->setValue(wide-num_of_streams);

}

void ttv::MonitorLUFs()
{
    QString prog = "ffmpeg";
    QString time = "-t";
    QString timelen = "10";
    QString input = "-i";
    QString udplocal;
    QString audiofilter = "-af";
    QString filter_name;
    QString file = "-f";
    QString null = "null";
    QString dash = "-";
    QString jibber ="2<&1";

    QStringList argu;

    while(redflag==false)
    {

        //ui->textBrowser->clear;

        //ffmpeg -t 1 -i udp://@234.31.32.36:3205 -af ebur128=framelog=verbose -f null - 2<&1 | awk '/I:/{print $2}'
        for(i=0;i<1;i++)
        {
            argu.clear();

            QProcess *monitor = new QProcess;\

            udplocal = streamid.at(i);
            argu<<time<<timelen<<input<<udplocal<<audiofilter<<filter_name<<file<<null<<dash<<jibber;

        }
    }
}

void ttv::ShowQVideos()
{

    wide=ui->width_spinBox->value();
    high=ui->height_spinBox->value();
    posx=posy=20;
    sidcnt--;

    for(i=0;i<sidcnt;i++)
    {
        QMediaPlaylist *playlist =new QMediaPlaylist;
        playlist->clear();
        playlist->addMedia(QUrl(streamid.at(i)));
        playlist->setCurrentIndex(1);

        QMediaPlayer *player = new QMediaPlayer;
        player->setPlaylist(playlist);
       // player->setMuted(true);

        QVideoWidget *vw = new QVideoWidget;
        vw->setWindowTitle(nameid.at(i));
        vw->setGeometry(posx,posy,wide,high);
        player->setVideoOutput(vw);
        vw->show();
        player->play();

        posx=posx+wide;
        if(posx>desktopwidth-(posx/4))
        {
            posx=20;
            posy=posy+(high+titleSpace);
        }


    }
}

void ttv::ShowFFplays()
{
    QString progplayer = "ffplay";
    QString x = "-x";
    QString y = "-y";
    QString width;
    QString height;
    QString xpos;
    QString ypos;
    QString udplocal;
    QString wt = "-window_title";
    QString title;
    QString volume = "-volume";
    QString level ="0";


    //QString getactivewindow = "get_desktop_viewport";

    QStringList arguplay;


    wide=ui->width_spinBox->value();
    high=ui->height_spinBox->value();
    posx=posy=20;
    sidcnt--;
    titleSpace=ui->titleSpace_spinBox->value();

    width = QString::number(wide);
    height = QString::number(high);

    for(i=0;i<sidcnt;i++)
    {
        xpos=QString::number(posx);
        ypos=QString::number(posy);

        QProcess *player = new QProcess;


        arguplay.clear();


        udplocal=streamid.at(i);
        title.clear();
        title.append(nameid.at(i));
        arguplay<<udplocal<<wt<<title<<x<<width<<y<<height<<volume<<level;


        player->start(progplayer,arguplay);

        posx=posx+wide;
        if(posx>desktopwidth-(posx/4))
        {
            posx=20;
            posy=posy+(high+titleSpace);
            num=0;
            cnt++;
        }


    }
}

void ttv::ShowMPVs()
{
    QString progplayer = "mpv";
    QString width;
    QString height;
    QString xpos;
    QString ypos;
    QString geo;
    QString mute = "--mute";
    QString title;
    QString udplocal;
    QString font_sz= "--osd-font-size=55";
    QString osd_bar = "--osd-bar"; // this allows an osd
    QString messag = "--osd-msg1=VBR ${=video-bitrate} ABR ${=audio-bitrate}"; //bitrates in cycles
    QString color = "--osd-color=0.0/1.0/0.0"; // video parameters

    QStringList arguplay;

    wide=ui->width_spinBox->value();
    high=ui->height_spinBox->value();
    posx=posy=20;
    sidcnt--;
    titleSpace=ui->titleSpace_spinBox->value();

    width = QString::number(wide);
    height = QString::number(high);

    cnt=num=0;

    for(i=0;i<sidcnt;i++)
    {
        geo="--geometry=";
        xpos=QString::number(posx);
        ypos=QString::number(posy);

        geo.append(width+"x"+height);
        geo.append("+");
        geo.append(xpos);
        geo.append("+");
        geo.append(ypos);

        arguplay.clear();
        udplocal=streamid.at(i);
        title="--title=";
        title.append(nameid.at(i));

        QProcess *player = new QProcess;

        if(ui->bitrate_checkBox->isChecked() == true)
        {
            arguplay<<udplocal<<geo<<title<<mute<<font_sz<<osd_bar<<messag<<color;
        }
        else
        {
            arguplay<<udplocal<<geo<<title<<mute;
        }
        player->start(progplayer,arguplay);

        num++;
        posx=posx+wide;

        if(num>viewsPerRow-1)
        {
            posx=20;
            posy=posy+high+titleSpace;
            num=0;
            cnt++;
         }


    }
}

void ttv::on_ffplay_pushButton_clicked()
{
    ShowFFplays();
}

void ttv::on_setMPVs_pushButton_clicked()
{
   // on_rows_wanted_spinBox_valueChanged(1);
    ShowMPVs();
}

void ttv::on_pushButton_clicked()
{
    MonitorLUFs();
}


void ttv::on_rows_wanted_spinBox_valueChanged(int arg1)
{
    int remain;
    titleSpace=ui->titleSpace_spinBox->value();
    rows=arg1;
    viewsPerRow=num_of_streams/rows;
    remain=num_of_streams%rows;
    if(remain>0)
        viewsPerRow++;
    wide=desktopwidth/(viewsPerRow);
    high=(desktopheight-(rows*titleSpace))/rows;
    ui->width_spinBox->setValue(wide-num_of_streams);
    ui->height_spinBox->setValue(high);

}
