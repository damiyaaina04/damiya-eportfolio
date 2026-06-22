#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void readFile(const string &TemperatureFile, float numF[], int &numData);
void computeC(float numF[], float numC[], int numData);
float average(float numC[], int &numData);
char grade(float numC[], int &numData, char categories[]);
void writeFile(float numF[], float numC[], int numData, char categories[]);

int main()
{
  const int i = 60;
  int  sumH = 0, sumM = 0, sumL = 0, numData;
  float numF[i], numC[i], avrg;
  char categories[i];
  
    readFile("TemperatureFile.txt",numF, numData);
    computeC(numF, numC, numData);
    avrg = average(numC, numData); 
    grade(numC, numData, categories); 
  
  for(int i=0;i<numData;i++){
        switch (categories[i]) {
            case 'H':
                sumH += numC[i];
                break;
            case 'M':
                sumM += numC[i];
                break;
            case 'L':
                sumL += numC[i];
                break;
            default:
                break;
        }
}
   
  writeFile(numF, numC, numData, categories);
  
  cout<<"Average of the temperature in Celcius : "<<fixed<<setprecision(1)<<avrg<<"\n";
  cout<<"Number of high temperature : "<<sumH<<"\n";
  cout<<"Number of medium temperature : "<<sumM<<"\n";
  cout<<"Number of low temperature : "<<sumL<<"\n";

return 0;
}

void readFile(const string &TemperatureFile, float numF[], int &numData)
{
  int i = 0 ;
  
  ifstream input;
  input.open("TemperatureFile.txt");
  
  if (!input)
  {
    cout << "Error in opening files" << endl;
  }  
  else
  cout << "File is ready to read " << endl; 
  
  numData = 0;
   while (input >> numF[i])
    {
        numData++;
        i++; 
    }

  input.close();
}

void computeC(float numF[], float numC[], int numData)
{
    for (int i = 0; i < numData; i++)
    {
        numC[i] = (5.0 / 9.0) * (numF[i] - 32);
    }
}

float average(float numC[], int &numData)
{
  float sum ,avrg;
  int i;
  sum = 0;
  
  for(i=0;i<numData;++i)
  {
    sum += numC[i];
  }
  avrg = sum/static_cast<float>(numData);
  return avrg;
}

char grade(float numC[], int &numData, char categories[])
{
  
  int i;
  for( i = 0; i<numData;i++)
  {
    if(numC[i]>=35){
       categories[i] = 'H';
	} else if ((numC[i]<35)&&(numC[i]>=20)){
    categories[i] = 'M';
    } else {
    categories[i] = 'L';
    }
    
  }
  return categories[i];
}

void writeFile(float numF[], float numC[], int numData, char categories[])
{
  int i;
  
  ofstream output;
  output.open("outputTemperatureFile.txt");
  
  output<<setw(15)<<"C(Celcius)"<<setw(15)<<"F(Fahrenheit)"<<setw(15)<<"Description\n";
  output<<setw(15)<<"==========="<<setw(15)<<"============"<<setw(15)<<"===========\n";
  for (int i = 0; i < numData; i++)
    {
        output<< setw(13)<< fixed<< setprecision(2)<< numC[i];
		output<< setw(14)<< fixed<< setprecision(2)<< numF[i]; 
		output<< setw(13) << categories[i] << "\n";
    }
  
  output.close();
}
