#include <vector>
#include <iostream>

using namespace std;

// void invert(vector<bool> &v)
// {
//   v.flip();
//   for (int i = 0; i < v.size(); i++)
//     cout << v[i];
// }

vector<bool> And(vector<bool> v1, vector<bool> v2)
{
  vector<bool> vector3;

  for (int i = 0; i < v1.size(); i++)
  {
    if (v1[i] == true && v2[i] == true)
    {
      vector3.push_back(true);
    }
    else
    {
      vector3.push_back(false);
    }
  }
  return vector3; 
}

int main()
{
  vector<bool> vector1 = {false, true, false, true, false, true};

  vector<bool> vector2 = {true, true, false, true, false, true};

  vector<bool> result = And(vector1, vector2); 

  for (auto element: result) 
    cout << element; 
}
