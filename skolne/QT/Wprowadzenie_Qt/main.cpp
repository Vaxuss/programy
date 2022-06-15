#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QTextStream>
#include <AAA.h>
#include <thing.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int dash = 30;
    QTextStream cout(stdout);

    int i;
    {
        for(i = 0; i < dash; i++){
            cout<<"=";
        }
        cout<<endl;
    }

    cout << "i = "<< i << endl;
    Thing t1(1,2);
    Fraction f1,f2;
    f1.set(3,4);
    f2.set(11,12);
    cout<< "Pierwszy ulamek to: " << f1.toString() << endl;
    cout<< "\n Drugi ulamek, jako double, to:" << f2.toDouble() << endl;



    return 0;

 //  QTranslator translator;
 //  const QStringList uiLanguages = QLocale::system().uiLanguages();
 //  for (const QString &locale : uiLanguages) {
 //      const QString baseName = "Wprowadzenie_Qt_" + QLocale(locale).name();
 //      if (translator.load(":/i18n/" + baseName)) {
 //          a.installTranslator(&translator);
 //          break;
 //      }
 //  }

    return a.exec();
}
