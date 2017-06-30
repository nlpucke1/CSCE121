#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

int colorPath(const vector<vector<int> >& img, vector<vector<int> >& R, 
	vector<vector<int> >& G, vector<vector<int> >& B, 
	int color_r, int color_g, int color_b, int start_row)
{
	int COLS_COUNT = img.at(0).size();
	int ROWS_COUNT = img.size();
	int Current_Row = start_row;
	int Elevation_Count = 0;
	
	for(int j = 1; j < COLS_COUNT; j++)
	{
		int Current_col = j-1;
		int Current_elevation =  img.at(Current_Row).at(Current_col);
		int Min_Elevation_Change = 0;
		
		
		R.at(Current_Row).at(Current_col) = color_r; //Colors it Red or Green;
		G.at(Current_Row).at(Current_col) = color_g;
		B.at(Current_Row).at(Current_col) = color_b;

		if(Current_Row != (ROWS_COUNT-1))
		{
			Min_Elevation_Change = abs(Current_elevation - img.at(Current_Row+1).at(j));
		}
		
		else
		{
			Min_Elevation_Change = abs(Current_elevation - img.at(Current_Row).at(j));
		}

		
		int Next_row = Current_Row + 1;
		int Change_in_elevation = 0;

		if(Current_Row == 0)
		{
			for(int i = Current_Row; i <= Current_Row+1; i++)
			{
				Change_in_elevation = abs(Current_elevation - img.at(i).at(j));
				if(Change_in_elevation < Min_Elevation_Change)
				{
					Min_Elevation_Change = Change_in_elevation;
					Next_row = i;
				}
			}
			Current_Row = Next_row;
			Elevation_Count += Min_Elevation_Change;
		}
		
		else if(Current_Row == ROWS_COUNT-1)
		{
			Next_row = Current_Row;
			for(int i = Current_Row - 1; i <= Current_Row; i++)
			{
				Change_in_elevation = abs(Current_elevation - img.at(i).at(j));
				if(Change_in_elevation < Min_Elevation_Change)
				{
					Min_Elevation_Change = Change_in_elevation;
					Next_row = i;
				}
				
			}
			Current_Row = Next_row;
			Elevation_Count += Min_Elevation_Change;
		}

		else
		{
		for(int i = Current_Row - 1; i <= Current_Row + 1; i++)
			{
				Change_in_elevation = abs(Current_elevation - img.at(i).at(j));
				if(Change_in_elevation < Min_Elevation_Change)
				{
					Min_Elevation_Change = Change_in_elevation;
					Next_row = i;
				}
			}
			Current_Row = Next_row;
			Elevation_Count += Min_Elevation_Change;
		}
	}
	return Elevation_Count;
}

int main()
{
	int ROWS_COUNT = 0; 
	int COLS_COUNT = 0;  
	int fileInput = 0;
	int k = 0;
	int min1 = 0; 
	int Green_Row = 0;
	int Green_Row_Output = 0;
	vector <int> BUFFER;
	string fileName = "";

	cout << "Enter the number of rows and columns respectively: " << endl; 
	cin >> ROWS_COUNT >> COLS_COUNT; 
	cout << endl;


	cout << "Enter the file name: "; 
	cin >> fileName; 
	cout << endl;

	ifstream infs(fileName);
	if(infs.is_open())
	{
		while(infs >> fileInput)
			BUFFER.push_back(fileInput);
	}
	
	double MAX = BUFFER.at(0); 
	double MIN = BUFFER.at(0);
	vector < vector <int> >img(ROWS_COUNT, vector <int> (COLS_COUNT));
	vector < vector <double> >GREY_MATRIX(ROWS_COUNT, vector <double> (COLS_COUNT));
	vector < vector <int> > R(ROWS_COUNT, vector <int> (COLS_COUNT));
	vector < vector <int> > G(ROWS_COUNT, vector <int> (COLS_COUNT));
	vector < vector <int> > B(ROWS_COUNT, vector <int> (COLS_COUNT)); 
	vector <int> Elevation_Count;

	for(int i = 0; i < ROWS_COUNT; i++)
	{
		for (int j = 0; j < COLS_COUNT; j++)
		{
			img.at(i).at(j) = BUFFER.at(k);

			if(MAX < BUFFER.at(k))
			{
				MAX = BUFFER.at(k);
			}
			
			if(MIN > BUFFER.at(k))
			{
				MIN = BUFFER.at(k);
			}
	
			k = k+1;
		}	
	}

	for(int i = 0; i < ROWS_COUNT; i++)
	{
		for(int j = 0; j < COLS_COUNT; j++)
		{
			GREY_MATRIX.at(i).at(j) = (img.at(i).at(j) - MIN)/(MAX - MIN) * 255;
			R.at(i).at(j) = GREY_MATRIX.at(i).at(j);
			G.at(i).at(j) = GREY_MATRIX.at(i).at(j);
			B.at(i).at(j) = GREY_MATRIX.at(i).at(j);
		}
	}

	for(int i = 0; i < ROWS_COUNT; i++)
		{
			Elevation_Count.push_back(colorPath(img, R, G, B, 252, 23, 63, i));
		}

	min1 = Elevation_Count.at(0);
	for(int i = 0; i < Elevation_Count.size(); i++)
		{
			if(Elevation_Count.at(i) < min1)
			{
				min1 = Elevation_Count.at(i);
				Green_Row = i;
			}
		}
	
	temp1 = colorPath(img, R, G, B, 31, 253, 13, Green_Row);

	ofstream ofs("OUTPUT_FILE.ppm");
	if(ofs.is_open())
	{
		ofs << "P3" << endl;
		ofs << COLS_COUNT << " " << ROWS_COUNT << endl;
		ofs << 255 << endl;

		for(int i = 0; i < ROWS_COUNT; i++)
		{
			for(int j = 0; j < COLS_COUNT; j++)
			{
			ofs << R.at(i).at(j) << " " << G.at(i).at(j) << " " << " " << B.at(i).at(j)<< " ";
		    }
		}
	}

		return 0;
}