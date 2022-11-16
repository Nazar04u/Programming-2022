#include<iostream>
using namespace std;


enum DogBreeds {
	HUSKY,
	BULLDOG,
	HASKY


};
void add_element(DogBreeds* array, int n)
{
	for (int i = 0; i < n; ++i) {
		array[i] = DogBreeds(rand() % 3);
	}
}
int main()
{
	int n;
	cout << "enter n" << endl;
	cin >> n;
	DogBreeds* arry = new DogBreeds[n];
	add_element(arry, n);
	for (int i = 0; i < n; ++i)
	{
		switch (arry[i]) {
		    case 0:
				cout << "Breed-Husky" << endl;
			case 1:
				cout << "Breed-BULLDOG" << endl;
			case 2:
				cout << "Breed-Tasky" << endl;
		    


		}
	}


}