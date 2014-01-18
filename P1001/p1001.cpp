#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Student {
int    index;
string name;
int    a_score; //academic score
int    p_score; //political score
bool   leader;
bool   western;
int    paper;
int    scs;
};

const int scs_yuanshi = 8000;
const int scs_wusi    = 4000;
const int scs_youxiu  = 2000;
const int scs_xibu    = 1000;
const int scs_banji   = 850;

/*
void quick_sort(Student arr[], int a, int b) {
  if (a >= b)
    return;
  int pivot = a + rand() % (b - a + 1);
  int pivot_scs = arr[pivot].scs, pivot_index = arr[pivot].index;
  Student temp;
  temp = arr[b];
  arr[b] = arr[pivot];
  arr[pivot] = temp;
  int sep = a;
  for (int i=a;i<b;i++) {
    if ((arr[i].scs > pivot_scs) 
    || ((arr[i].scs == pivot_scs) && (arr[i].index < pivot_index))) {
      temp = arr[i];
      arr[i] = arr[sep];
      arr[sep++] = temp;
    }
  }
  temp = arr[b];
  arr[b] = arr[sep];
  arr[sep] = temp;
  quick_sort(arr, a, sep - 1);
  quick_sort(arr, sep + 1, b);
  return;
}
*/

int main() {
  int n;
  cin >> n;
  Student data[100];
  
  for (int i=0;i<n;i++) {
    char leader, western;
    data[i].index = i;
    cin>>data[i].name>>data[i].a_score>>data[i].p_score>>leader>>western>>data[i].paper;
    data[i].leader = (leader == 'Y');
    data[i].western = (western == 'Y');
    data[i].scs = 0;
    if ((data[i].a_score > 80) && (data[i].paper > 0))
      data[i].scs += scs_yuanshi;
    if ((data[i].a_score > 85) && (data[i].p_score > 80))
      data[i].scs += scs_wusi;
    if (data[i].a_score > 90)
      data[i].scs += scs_youxiu;
    if ((data[i].a_score > 85) && (data[i].western))
      data[i].scs += scs_xibu;
    if ((data[i].p_score > 80) && (data[i].leader))
      data[i].scs += scs_banji;
  }
  //srand(unsigned(time(0)));
  //quick_sort(data, 0, n-1);
  int sum = 0, max = 0;
  for (int i=0;i<n;i++) {
    sum += data[i].scs;
    if (data[i].scs > data[max].scs)
      max = i;
  }
  cout<<data[max].name<<endl<<data[max].scs<<endl<<sum<<endl;
  return 0;
}
