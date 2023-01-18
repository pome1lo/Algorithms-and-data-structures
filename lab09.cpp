#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

#define City 5

#define CHILD 3

#define START 0

#define POP_SIZE 5

int graph[City][City] = { { INT_MAX, 25, 40, 31, 27},
						  { 5, INT_MAX, 17, 30, 25},
						  { 19, 15, INT_MAX, 6, 1},
						  { 9, 50, 24, INT_MAX, 6 },
						  { 22, 8, 7, 10, INT_MAX } };
struct individual {
	string gnome;
	int fitness;
};

int rand_num(int start, int end) 
{
	int r = end - start;
	int rnum = start + rand() % r;
	return rnum;
}
// повтор
bool repeat(string s, char ch)
{
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ch)
			return true;
	}
	return false;
}
// мутация
string mutatedGene(string gnome)
{
	while (true) {
		int r = rand_num(1, City);
		int r1 = rand_num(1, City);
		if (r1 != r) {
			char temp = gnome[r];
			gnome[r] = gnome[r1];
			gnome[r1] = temp;
			break;
		}
	}
	return gnome;
}
// 
string create_gnome()
{
	string gnome = "0";
	while (true) {
		if (gnome.size() == City) {
			gnome += gnome[0];
			break;
		}
		int temp = rand_num(1, City);
		if (!repeat(gnome, (char)(temp + 48)))
			gnome += (char)(temp + 48);
	}
	return gnome;
}
// подсчет пути вес
int cal_fitness(string gnome)
{

	int f = 0;
	for (int i = 0; i < gnome.size() - 1; i++) {
		if (graph[gnome[i] - 48][gnome[i + 1] - 48] == INT_MAX)
			return INT_MAX;
		f += graph[gnome[i] - 48][gnome[i + 1] - 48];
	}
	return f;
}
// критерий остановки
int cooldown(int temp) 
{
	return (90 * temp) / 100;
}
// сортировка
bool lessthan(struct individual t1, struct individual t2)
{
	return t1.fitness < t2.fitness;
}

void GenAlg(int graph[City][City])
{
	int gen = 1;
	int gen_thres = 50;

	vector<struct individual> population;
	struct individual temp;

	for (int i = 0; i < POP_SIZE; i++) {
		temp.gnome = create_gnome();
		temp.fitness = cal_fitness(temp.gnome);
		population.push_back(temp);
	}

	cout << "\nНачальная численность: \n Пути  Значение\n";
	for (int i = 0; i < POP_SIZE; i++) 
	{
		cout << population[i].gnome << " " << population[i].fitness << endl;
	}
	cout << endl;

	int temperature = 1000;

	sort(population.begin(), population.end(), lessthan);

	while (temperature > 100 && gen <= gen_thres) {
		cout << "\nЛучший: " << population[0].gnome << endl;
		cout << "\nЛучший: " << population[0].fitness << "\t";

		vector<struct individual> new_population;

		for (int i = 0; i < CHILD; i++) {

			struct individual p1 = population[i];

			while (true)
			{
				string new_g = mutatedGene(p1.gnome);
				struct individual new_gnome;
				new_gnome.gnome = new_g;
				new_gnome.fitness = cal_fitness(new_gnome.gnome);

				if (new_gnome.fitness <= population[i].fitness) {
					new_population.push_back(new_gnome);
					break;
				}
				else {
					new_gnome.fitness = INT_MAX;
					new_population.push_back(new_gnome);
					break;
				}
			}
		}

		temperature = cooldown(temperature);
		for (int i = 0; i < CHILD; i++)
		{
			population.push_back(new_population[i]);
		}
		sort(population.begin(), population.end(), lessthan);

		for (int i = 0; i < CHILD; i++)
		{
			population.pop_back();
		}

		cout << "N: " << gen << " \n";
		cout << " Пути  Значение\n";

		for (int i = 0; i < POP_SIZE; i++)
			cout << population[i].gnome << " "
			<< population[i].fitness << endl;
		gen++;
	}
}
void main()
{
	setlocale(LC_ALL, "rus");
	
	GenAlg(graph);
}