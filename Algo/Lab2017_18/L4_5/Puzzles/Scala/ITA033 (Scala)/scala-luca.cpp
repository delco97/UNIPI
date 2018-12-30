#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

template<class T> struct area: public unary_function<T,void>
{
  long int val,max,prev;
  area():val(0),max(0),prev(0){}
  void operator() (const T& x) {
    if (x.second>max)
      {
	val+=(prev-x.first)*max;
	max=x.second;
	prev=x.first;
      }
  }
  virtual ~area() { val+=prev*max; fout<<val<<endl;  fout.close();}
};

int main()
{
 
  int N,i,x,y;

  fin>>N;
  map<int,int> coord;
  for(i=0;i<N;i++)
    {
      fin>>x>>y;
      if ( coord.find(x)==coord.end() || coord[x]<y )coord[x]=y;
    }

  for_each(coord.rbegin(),coord.rend(), area<const pair<int,int> >() );
}
