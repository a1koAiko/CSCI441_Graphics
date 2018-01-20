//stdio added for my own testing in the begining
#include <stdio.h>
//part 4, added iostream library
#include <iostream>
#include <string>
#include <cstdlib>

//part 5a classes and structs
//Copy the definition of Vector3 into main.cpp file,
//Test V3.add works by adding 2 vectors together and printing out the result.

class Vector3 { public:
  float x; float y; float z;
  // Constructor
  Vector3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {
    // nothing to do here as we've already initialized x, y, and z above std::cout << "in Vector3 constructor" << std::endl;
  }

  // Destructor - called when an object goes out of scope or is destroyed
  ~Vector3() {
    // this is where you would release resources such as memory or file descriptors // in this case we don't need to do anything
    std::cout << "in Vector3 destructor" << std::endl;
  }

  float helperNumber;
  friend std::ostream& operator<<(std::ostream& stream, const Vector3& o);

  //part 8 add a default constructor to Vector3
  //int* array_of_ints = new int[100];
  // allocates 100 consecutive ints and returns a pointer
  //delete [] array_of_ints; // frees all the memory we just allocated

  protected: Vector3* vArray[];
    Vector3()
    {
      vArray[10] = new Vector3[10];
    for (int i = 0; i < 10; i++){
      std::cout << *vArray << "******"<< std::endl;
    }
  };
};

//part 5b finish implementation of Vector3 add(Vector3 v, Vector3 v2)
Vector3 add(Vector3 v, Vector3 v2) {
  // v and v2 are copies, so any changes to them in this
  // won't affect the originals ...

  v.x = v.x + v2.x;
  v.y = v.y + v2.y;
  v.z = v.z + v2.z;
  return v;
}
//part 6a operator overloading + (oo+)
Vector3 operator +(Vector3 v, Vector3 v2){

  Vector3 c = add(v,v2);
  return c;
} //part 6b oo*
Vector3 operator *(float s, Vector3 v) {
  v.x = s * v.x;
  v.y = s * v.y;
  v.z = s * v.z;
  return v;
} //part 6b oo* continued.
Vector3 operator *(Vector3 v, float s) {
  v.x = s * v.x;
  v.y = s * v.y;
  v.z = s * v.z;
  return v;
}

std::ostream& operator<<(std::ostream& stream, const Vector3& v){
  // std::cout is a std::ostream object, just like stream
  // so use stream as if it were cout and output the components of
  // the vector

  return stream;
}
//part 1 instantiate a main
int main(int argc, char**argv) {


  //part 3 namespace mapping
  using std::cout;
  using std::endl;
  //part 4 Basic terminal I/O part 4a - output
  cout << "\nHello World \n" <<  argv[0] <<" " << 1234 << " " << endl;

  //part 4b - input/output
  std::string answer;
  using std::cin;
  cout << "\nHello, what is your name?" << endl;
  cin >> answer;
  cout << "\nHello <" << answer << ">" << endl;
  cout << answer << ", are you ready for vector math?\n" << endl;

  //part 5c finish implementation of Vector3 add(Vector3 v, Vector3 v2)
  cout <<  answer << " lab0 will now add [1,2,3] + [4,5,6]" <<
  "\nThe expected result is [5,7,9]\n" << endl;
  Vector3 a(1,2,3);   // allocated to the stack
  Vector3 b(4,5,6);
  a = add(a,b);
  cout << "The resulting sum Vector is [" <<
  a.x << ", " << a.y << ", "<< a.z << "]\n" << endl;
  cout << "END_TEST___________________________" << endl;

  //part 6a operator+ overloading
  cout << answer << ", given the vectors [2,3,4] and [1,1,1]\n" <<
  "we get a new vector [3,4,5] using operator overloading." << endl;
  Vector3 P0(2,3,4);
  Vector3 P1(1,1,1);
  //std::cout << P0 + P1 << "\n" << std::endl;
  cout << "END_TEST____________________******" << endl;
  Vector3 Q = operator+(P0,P1);
  cout << "\n  The Vector result of operator overloading addition is ["
  << Q.x << ", " << Q.y << ", " << Q.z  << "].\n" << endl;
  cout << "END_TEST___________________________" << endl;



  //part 6b operator* overloading test
  float t = .33, u = .5;
  Vector3 Z = operator*(t,P0);
  cout << "\n\n" << answer << ", given the vector [3,4,5] and the scalar .33\n" <<
  "we get a new vector [.66, .99, .1.32] using operator overloading." << endl;
  cout << "  And the vector from scalar multiplication; ["
  << Z.x << ", " << Z.y << ", " << Z.z << "].\n " << endl;
  cout << "END_TEST___________________________" << endl;
  //part 6b continued. another way to multiply a scalar and a vector.
  Vector3 Zz = operator*(u,P1);
  cout << "\n\n" << answer << ", given the vector [1,1,1] and the scalar .5\n" <<
  "we get a new vector [.5, .5, .5] using operator overloading." << endl;
  cout << "  And the vector from scalar multiplication; ["
  << Zz.x << ", " << Zz.y << ", " << Zz.z << "].\n " << endl;
  cout << "END_TEST___________________________" << endl;
  //part 6c operator<< overloading
  Vector3 v(1,2,3);
  Vector3* vecPointer = &v;
  Vector3 v1(4,5,6);
  Vector3* vecPointer1 = &v1;
  std::cout << *vecPointer + *vecPointer1 << std::endl;
  cout << "END_TEST___________________________" << endl;

  //Part 7 pointers
  Vector3 startVec(0,0,0);
  int i = 5;
  int* pointer_to_i = &i;
  startVec.y = *pointer_to_i;
  cout << "  The vector [0,0,0] changed to [0,5,5] via pointers; \n      ["
  << startVec.x << ", " << startVec.y << ", " << startVec.z << "].\n " << endl;
  std::cout << *pointer_to_i << std::endl; // will print out 5
  cout << "END_TEST___________________________" << endl;

  //part 8 arrays
  //Allocate an array of 10 Vector3 objects on the stack.
  //Make any necessary changes to get your code to compile.

  int newY = 5;
  Vector3 vec2array(0,0,0);
  for (int i = 0; i < 10; i++){
    vec2array.y = newY;
  //  vArray[i] = vec2Array;
  }
}
