#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <time.h>

using namespace std;

const string currentDateTime()
{
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);

  strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);


  return buf;
}



int main()
{
  int stars;
  string tag;
  string sterne = "Sterne";
  string stern = "Stern";
  string umbruch = "\n";
  cout << "Wie war dein tag heute?" << endl;
  getline(cin, tag);
  ofstream out;
  out.open("tagebuch.txt", ios::app);

  out << currentDateTime() << endl;

  if( tag.length() > 30)
    {
      tag.insert(30, umbruch);
      out << tag << endl;
    }


  cout << "Bewerte deinen Tag" << endl;
  cin >> stars;
  if (stars > 1)
  {
    out << stars << sterne << endl;
  }
  else
  {
    out << stars << stern << endl;
  }
  string cutter = "############################################";
  out << cutter << endl;

  return 0;
}
