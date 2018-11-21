#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "ArgumentManager.h"
using namespace std;


class Date // class for the date variable in the class student
{
private:
	int Day;
	int Month;
	int Year;

public:
	Date()
	{
		Day = 0;
		Month = 0;
		Year = 0;
	}

	Date(int newYear, int newMonth, int newDay) {
		Year = newYear;
		Month = newMonth;
		Day = newDay;
	}

	void setDate(int nYear, int nMonth, int nDay)
	{
		Year = nYear;
		Month = nMonth;
		Day = nDay;
	}
	
	int getYear()
	{
		return Year;
	}

	int getMonth()
	{
		return Month;
	}

	int getDay()
	{
		return Day;
	}
	
	bool operator<(const Date &obj)
	{
		if (Year < obj.Year)
		{
			return true;
		}
		else if (Year > obj.Year)
		{
			return false;
		}
		else
		{
			if (Month < obj.Month)
			{
				return true;
			}
			else if (Month > obj.Month)
			{
				return false;
			}
			else
			{
				if (Day < obj.Day)
				{
					return true;
				}
				else if (Day > obj.Day)
				{
					return false;
				}
			}
		}

		return false;
	}

	bool operator==(const Date&obj)
	{
		return (Year == obj.Year&&Month == obj.Month && Day == obj.Day);
	}

	void operator=(const Date &obj)
	{
		Year = obj.Year;
		Month = obj.Month;
		Day = obj.Day;
	}

	friend ostream &operator << (ostream &outFile, Date &obj)
	{
		string var1;
		string var2;

		if (obj.Month < 10)
		{

			var1 = "0" + to_string(obj.Month);
		}
		else if (obj.Month >= 10)
		{
			var1 = to_string(obj.Month);
		}

		if (obj.Day < 10)
		{
			var2 = "0" + to_string(obj.Day);

		}
		else if (obj.Day >= 10)
		{
			var2 = to_string(obj.Day);
		}

		outFile << obj.Year << "-" << var1 << "-" << var2;
		return outFile;
	}

	bool operator<=(const Date &obj)
	{
		if (Year < obj.Year)
		{
			return true;
		}
		else if (Year > obj.Year)
		{
			return false;
		}
		else
		{
			if (Month < obj.Month)
			{
				return true;
			}
			else if (Month > obj.Month)
			{
				return false;
			}
			else
			{
				if (Day <= obj.Day)
				{
					return true;
				}
				else if (Day > obj.Day)
				{
					return false;
				}
			}
		}
	}

	

	bool operator>=(const Date &obj)
	{
		if (Year > obj.Year)
		{
			return true;
		}
		else if (Year < obj.Year)
		{
			return false;
		}
		else
		{
			if (Month > obj.Month)
			{
				return true;
			}
			else if (Month < obj.Month)
			{
				return false;
			}
			else 
			{
				if (Day >= obj.Day)
				{
					return true;
				}
				else if (Day < obj.Day)
				{
					return false;
				}
			}
		}
	}
	
};

class Student // class that contains its unique features of a student
{
private:
	string studentID, firstName, lastName, major;
	float GPA;
	Date DOB;
public:
	Student()
	{
		studentID = "";
		firstName = "";
		lastName = "";
		DOB.setDate(0, 0, 0);
		major = "";
		GPA = 0;
	}
	Student(string nStud, string nFirst, string nLast, Date nDOB, string nMajor, float nGPA) {
		studentID = nStud;
		firstName = nFirst;
		lastName = nLast;
		DOB = nDOB;
		major = nMajor;
		GPA = nGPA;
	}

	string getID()
	{
		return studentID;
	}

	string getFirstName()
	{
		return firstName;
	}

	string getLast()
	{
		return lastName;
	}

	Date getDate()
	{
		return DOB;
	}

	string getMajor()
	{
		return major;
	}
	
	float getGPA()
	{
		return GPA;
	}

	void setID(string nStudentID)
	{
		studentID = nStudentID;
	}

	void setName(string nFirstName, string nLastName)
	{
		firstName = nFirstName;
		lastName = nLastName;
	}

	void setDOB(Date nDOB)
	{
		DOB = nDOB;
	}
	
	void setMajor(string nMajor)
	{
		major = nMajor;
	}
		
	void setGPA(float nGPA)
	{
		GPA = nGPA;
	}

	friend ostream &operator << (ostream &outFile, Student &obj)
	{

		outFile << obj.studentID << "," << obj.firstName << "," << obj.lastName << "," << obj.DOB << "," << obj.major << "," <<fixed<<setprecision(2)<< obj.GPA;
		return outFile;
	}

	void operator = (const Student &obj)
	{
		studentID = obj.studentID;
		firstName = obj.firstName;
		lastName = obj.lastName;
		GPA = obj.GPA;
		major = obj.major;
		DOB = obj.DOB;
	}

	bool operator< (const Student &obj)
	{
		if (studentID < obj.studentID) return true;
		return false;
	}
};


template <class DataType>
class ArrayList // this class contains it's unique features for an array list
{
private:
	DataType *list;
	int length;
	int maxSize; 
	int counter;

public:

	ArrayList(int size)
	{
		if (size <= 0)
		{
			maxSize = 100;
		}
		else
		{
			maxSize = size;
			length = 0;
		}
		list = new DataType[maxSize];
	}

	~ArrayList()
	{
		maxSize = 0;
		length = 0;
		counter = 0;
		delete[] list;
	}

	bool isEmpty() const
	{
		if (length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isFull() const
	{
		if (length == maxSize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int listSize() const
	{
		return length;
	}
	
	void print()
	{
		for (int i = 0; i < length;i++)
		{

			cout << " " << list[i] << endl;
		}
	}

	void insertAt(int position, const DataType &item)
	{
		int i = 0;
		if (position < 0 || position >= maxSize)
		{
			cout << "ERROR: Out of range! Cannot insertAVL!" << endl;
		}
		else
		{
			if (isFull())
			{
				cout << "ERROR: List is already full! Cannot insertAVL!" << endl;
			}
			else
			{
				while (list[i] < item && i < length)
				{
					i++;
				}

				if (i == length)
				{
					list[i] = item;
					length++;
				}
				else
				{
					for (int j = length;j > i;j--)
					{
						list[j] = list[j - 1];
					}
					list[i] = item;
					length++;
				}
			}
		}
	}

	void retrieveAt(int position, DataType &item)
	{
		if (position < 0 || position >= length)
		{
			cout << "ERROR: Out of range! Cannot retrieve at desired position!" << endl;
		}
		else
		{
			item = list[position];
		}
	}

	void searchStudentID_1(const string &item, int& vari) // sequential search for obj studentID
	{
		for (int pos = vari; pos < length; pos++)
		{
			if (list[pos].getID() == item)
			{
				vari = (pos + 1);
				return;
			}
		}
		vari = -1;
	}

	void searchFirstName(const string &item, int& vari) // sequential search for first name
	{
		for (int pos = vari; pos < length; pos++)
		{
			if (list[pos].getFirstName() == item)
			{
				vari = (pos + 1);
				return;
			}
		}
		vari = -1;
	}

	void searchLastName(const string &item, int& vari) // sequential search for last name
	{
		for (int pos = vari; pos < length; pos++)
		{
			if (list[pos].getLast() == item)
			{
				vari = (pos + 1);
				return;
			}
		}
		vari = -1;
	}

	void searchDOB(const Date &item, int& vari) // sequential search for DOB
	{
		for (int pos = vari; pos < length; pos++)
		{
			if (list[pos].getDate() == item)
			{
				vari = (pos + 1);
				return;
			}
		}
		vari = -1;
	}

	void searchMajor(const string &item, int& vari) // sequential search for major
	{
		for (int pos = vari; pos < length; pos++)
		{
			if (list[pos].getMajor() == item)
			{
				vari = (pos + 1);
				return;
			}
		}
		vari = -1;
	}

	void searchGPA(const float &item, int& vari) // sequential search for gpa
	{
		for (int pos = vari; pos < length; pos++)
		{
			if (list[pos].getGPA() == item)
			{
				vari = (pos + 1);
				return;
			}
		}
		vari = -1;
	}

	int searchStudentID_2(ArrayList *ptr, int leftSide, int rightSide, string var, int& counter) // binary search for obj studentID
	{
		int middle;
		int position;

		if (rightSide < leftSide)
		{
			return -1;
		}

		middle = (leftSide + rightSide) / 2;

		DataType value;
		
		retrieveAt(middle, value);
		
		if (var == value.getID()) 
		{
			position = middle;
			counter++;
			return position;
		}
		else if (var < value.getID()) {
			counter++;
			return searchStudentID_2(ptr, leftSide, middle - 1, var, counter);
		}
		
		counter++;
		
		return searchStudentID_2(ptr, middle + 1, rightSide, var, counter);

	}
};

struct Node 
{
	int info;
	Node* next;

	Node()
	{
		info = 0;
		next = NULL;
	}

	Node(int var)
	{
		info = var;
		next = NULL;
	}
};

class NodeList {	// link list class
private:
	Node* firstNamePtr; 
	Node* lastNamePtr; 

public:
	NodeList()
	{
		firstNamePtr = NULL;
		lastNamePtr = NULL;
	}

	bool emptyList()
	{
		return (firstNamePtr == NULL);
	}

	~NodeList()
	{
		while (!emptyList())
		{
			clear();
		}
	}

	Node *firstPtrVar()
	{
		return firstNamePtr;
	}

	void addNode(int var2)
	{
		Node *nodePtr = new Node(var2);
		if (firstNamePtr == NULL)
		{
			firstNamePtr = nodePtr;
			lastNamePtr = nodePtr;
		}
		else
		{
			lastNamePtr->next = nodePtr;
			lastNamePtr = nodePtr;

		}
	}

	void clear()
	{
		if (!emptyList())
		{
			Node *tempPtr = firstNamePtr;
			firstNamePtr = firstNamePtr->next;
			delete tempPtr;
		}
	}
	
	void operator=(const NodeList& object)
	{
		Node* current = object.firstNamePtr;
		while (current != NULL)
		{
			addNode(current->info);
			current = current->next;
		}
	}
	
};


template <class DataType>
struct Node2 // this struct is for the avl node
{
	
	NodeList i;
	DataType key;
	int bal;
	Node2<DataType> *llink;
	Node2<DataType> *rlink;

	Node2()
	{
		key = NULL;
		bal = 0;
		llink = NULL;
		rlink = NULL;
	}
	Node2(DataType nKey, int var, int newBal)
	{
		key = nKey;
		llink = NULL;
		rlink = NULL;
		bal = newBal;
		i.addNode(var);
	}

};

template <class DataType>
class AVLBinaryTree // contains its unique features of an avl binary tree
{
private:
	Node2<DataType> *root;

public:
	AVLBinaryTree()
	{
		root = NULL;
	}

	~AVLBinaryTree()
	{
		deleteTree(root);
	}

	void deleteTree(Node2<DataType> *Var)
	{
		if (Var != NULL)
		{
			deleteTree(Var->llink);
			deleteTree(Var->rlink);
			delete Var;
		}
	}

	void addToAVL(Node2<DataType> *&node, DataType item, int vable, bool &isTaller)
	{
		if (node == NULL)
		{
			node = new Node2<DataType>(item, vable, 0);
			isTaller = true;
			return;
		}
		if (item == node->key)
		{
			node->i.addNode(vable);
		}
		else if (item < node->key)
		{
			addToAVL(node->llink, item, vable, isTaller);
			if (isTaller)
				switch (node->bal)
				{
				case -1:
					balanceLeftSide(node);
					isTaller = false;
					break;
				case 0:
					node->bal = -1;
					isTaller = true;
					break;
				case 1:
					node->bal = 0;
					isTaller = false;
					break;
				}
		}
		else
		{
			addToAVL(node->rlink, item, vable, isTaller);
			if (isTaller)
				switch (node->bal)
				{
				case -1:
					node->bal = 0;
					isTaller = false;
					break;
				case 0:
					node->bal = 1;
					isTaller = true;
					break;
				case 1:
					balanceRightSide(node);
					isTaller = false;
				}
		}
	}

	void balanceLeftSide(Node2<DataType> *&ptr)
	{
		Node2<DataType> *tempPtr1;
		Node2<DataType> *tempPtr2;
		tempPtr1 = ptr->llink;
		switch (tempPtr1->bal)
		{
		case -1:
			ptr->bal = 0;
			tempPtr1->bal = 0;
			adjustR(ptr);
			break;
		case 1:
			tempPtr2 = tempPtr1->rlink;
			switch (tempPtr2->bal)
			{
			case -1:
				ptr->bal = 1;
				tempPtr1->bal = 0;
				break;
			case 0:
				ptr->bal = 0;
				tempPtr1->bal = 0;
				break;
			case 1:
				ptr->bal = 0;
				tempPtr1->bal = -1;
			}
			tempPtr2->bal = 0;
			adjustL(tempPtr1);
			ptr->llink = tempPtr1;
			adjustR(ptr);
		}
	}
	void balanceRightSide(Node2<DataType> *&ptr)
	{
		Node2<DataType> *tempPtr1;
		Node2<DataType> *tempPtr2;
		tempPtr1 = ptr->rlink;
		switch (tempPtr1->bal)
		{
		case -1:
			tempPtr2 = tempPtr1->llink;
			switch (tempPtr2->bal)
			{
			case -1:
				ptr->bal = 0;
				tempPtr1->bal = 1;
				break;
			case 0:
				ptr->bal = -1;
				tempPtr1->bal = 0;
				break;
			case 1:
				ptr->bal = -1;
				tempPtr1->bal = 0;
			}
			tempPtr2->bal = 0;
			adjustR(tempPtr1);
			ptr->rlink = tempPtr1;
			adjustL(ptr);
			break;
		case 1:
			ptr->bal = 0;
			tempPtr1->bal = 0;
			adjustL(ptr);
		}

	}

	void insertAVL(const DataType &var, int i)
	{
		bool isTaller = false;
		addToAVL(root, var, i, isTaller);
	}

	void searchList(NodeList& node, DataType item, Node2<DataType>  *&leaf, int& count) 
	{

		if (leaf == NULL)
		{
			node = NodeList();
			return;
		}
		if (item == leaf->key)
		{
			count++;
			node = leaf->i;
			return;
		}
		if (item < leaf->key)
		{
			count++;
			searchList(node, item, leaf->llink, count);
			return;
		}
		else
		{
			count++;
			searchList(node, item, leaf->rlink, count);
			return;
		}
		node = NodeList();
	}

	void searchList2(NodeList & node, DataType item, int &i)
	{

		searchList(node, item, root, i);
	}

	void adjustR(Node2<DataType> *&ptr)
	{
		Node2<DataType> *tempPtr1;
		if (ptr == NULL)
		{
			cout << "ERROR: Cannot insertAVL because tree is already empty!" << endl;
		}
		else if (ptr->llink == NULL)
		{
			cout << "ERROR: There is no subtree to rotate!" << endl;
		}
		else
		{
			tempPtr1 = ptr->llink;
			ptr->llink = tempPtr1->rlink;
			tempPtr1->rlink = ptr;
			ptr = tempPtr1;
		}
	}

	void adjustL(Node2<DataType> *&ptr)
	{
		Node2<DataType> *tempPtr1;
		if (ptr == NULL)
		{
			cout << "ERROR: Cannot adjust because tree is already empty!" << endl;
		}
		else if (ptr->rlink == NULL)
		{
			cout << "ERROR: There is no subtree to rotate!" << endl;
		}
		else
		{
			tempPtr1 = ptr->rlink;
			ptr->rlink = tempPtr1->llink;
			tempPtr1->llink = ptr;
			ptr = tempPtr1;
		}


	}
};


int main(int argc, char *argv[])
{

	Student obj;
	ArgumentManager am(argc, argv);
	ArrayList<Student> list(100);
	string firstName, lastName, major, Year, Month, Day, studentID, var1 ,var2;
	string dataBase = am.get("A");
	string keyFile = am.get("B");
	string txtFile = am.get("C");
	ifstream readFile(dataBase);
	ifstream readFile2(keyFile);
	ofstream outFile(txtFile);
	AVLBinaryTree<string> id;
	AVLBinaryTree<string> nMajor;
	AVLBinaryTree<string>nFirst;
	AVLBinaryTree<string>nLast;
	AVLBinaryTree<Date> nDate;
	AVLBinaryTree<float>nGPA;
	string conversion;
	float GPA;
	
	if (readFile.fail())
	{
		cout << "ERROR: Cannot open file!" << endl;
	}
	else
	{
		int i = 0;
		while (getline(readFile, var1))
		{
			stringstream parsing(var1);
			getline(parsing, studentID, ',');
			getline(parsing, firstName, ',');
			getline(parsing, lastName, ',');
			getline(parsing, Year, '-');
			getline(parsing, Month, '-');
			getline(parsing, Day, ',');
			getline(parsing, major, ',');
			getline(parsing, conversion);
			GPA = stof(conversion);
			obj.setID(studentID);
			obj.setName(firstName, lastName);
			obj.setMajor(major);
			obj.setGPA(GPA);
			obj.setDOB(Date(stoi(Year), stoi(Month), stoi(Day)));
			cout << "" << studentID << "," << firstName << "," << lastName << "," << Year << "-" << Month << "-" << Day << "," << major << ", " << GPA << endl;
			list.insertAt(i, obj);
			i++;

		}
		for (int j = 0;j < i;j++) {
			list.retrieveAt(j, obj);
			id.insertAVL(obj.getID(), j);
			nFirst.insertAVL(obj.getFirstName(), j);
			nLast.insertAVL(obj.getLast(), j);
			nDate.insertAVL(obj.getDate(), j);
			nMajor.insertAVL(obj.getMajor(), j);
			nGPA.insertAVL(obj.getGPA(), j);

		}
		NodeList index;
		while (getline(readFile2, var2, ':'))
		{
	
			if (var2 == "ID")
			{

				ofstream writeFile(txtFile.c_str());
		
				getline(readFile2, studentID);

				if (studentID[0] == ' ')
				{
					studentID.erase(0, 1);
				}

				int counter = 0;

				id.searchList2(index, studentID, counter); 

				Node* current = index.firstPtrVar();

				Student object;

				int counterForList = 0;

				if (current == NULL) 
				{
					list.searchStudentID_2(&list, 0, list.listSize(), studentID, counterForList);
					writeFile << "No record found for " << var2 << " " << studentID << endl;
					writeFile << "Without index: " << counterForList << " accesses" << endl;
				}
				else
				{
					while (current != NULL) 
					{
						int pos = current->info;
						list.searchStudentID_2(&list, 0, list.listSize(), studentID, counterForList);
						list.retrieveAt(pos, object);
						writeFile << object << endl;
						current = current->next;
						writeFile << "Without index: " << counterForList << " accesses" << endl << endl;
					}

				}
				writeFile.close();
			}

			if (var2 == "FIRSTNAME")
			{
				ofstream writeFile(txtFile.c_str());
			
				getline(readFile2, firstName);
				
				int counter = 0;

				nFirst.searchList2(index, firstName, counter);
				
				Node* current = index.firstPtrVar();

				Student object;

				int counterForList = 0;

				if (current == NULL) 
				{
					writeFile << "No record found for " << var2 << " " << firstName << endl;
					writeFile << "Without index: " << list.listSize() << " accesses" << endl;
					writeFile << "With index: " << counter + 1 << " accesses" << endl;
				}
				else
				{
					while (current != NULL)
					{
						int pos = current->info;
						list.searchFirstName(firstName, counterForList);
						list.retrieveAt(pos, object);
						writeFile << object << endl;
						current = current->next;
						writeFile << "Without index: " << counterForList << " accesses" << endl;
						writeFile << "With index: " << counter + 2 << " accesses" << endl << endl;
					}

				}
				writeFile.close();
			}

			if (var2 == "LASTNAME")
			{
				ofstream writeFile(txtFile.c_str());
			
				getline(readFile2, lastName);
			
				int counter = 0;

				nLast.searchList2(index, lastName, counter); 

				Node* current = index.firstPtrVar();

				Student object;

				int counterForList = 0;

				if (current == NULL) 
				{
					writeFile << "No record found for " << var2 << " " << lastName << endl;
					writeFile << "Without index: " << list.listSize() << " accesses" << endl;
					writeFile << "With index: " << counter << " accesses" << endl;
				}
				else
				{
					while (current != NULL)
					{
						int pos = current->info;
						list.retrieveAt(pos, object);
						list.searchLastName(lastName, counterForList);
						writeFile << object << endl;
						current = current->next;
						writeFile << "Without index: " << counterForList << " accesses" << endl;
						writeFile << "With index: " << counter + 1 << " accesses" << endl << endl;
					}

				}
				writeFile.close();
			}

			if (var2 == "DOB")
			{
				ofstream writeFile(txtFile.c_str());
		
				getline(readFile2, Year, '-');

				getline(readFile2, Month, '-');

				getline(readFile2, Day);
				
				int counter;

				int counterForList;

				counter = 0;

				counterForList = 0;

				nDate.searchList2(index, Date(stoi(Year), stoi(Month), stoi(Day)), counter);
				
				Node* current = index.firstPtrVar();
				
				Student object;
				
				string vari1;
				
				string vari2;
				
				if (stoi(Month) < 10)
				{

					vari1 = "0" + Month;
				}
				else if (stoi(Month) >= 10)
				{
					vari1 = Month;
				}

				if (stoi(Day) < 10)
				{
					vari2 = "0" + Day;

				}
				else if (stoi(Day) >= 10)
				{
					vari2 = Day;
				}

				if (current == NULL) 
				{
					writeFile << "No record found for " << var2 << " " << Year << "-" << vari1 << "" << "-" << vari2 << endl;
					writeFile << "Without index: " << list.listSize() << " accesses" << endl;
					writeFile << "With index: " << counter << " accesses" << endl;
				}
				else
				{
					while (current != NULL)
					{
						int pos = current->info;
						list.searchDOB(Date(stoi(Year), stoi(Month), stoi(Day)), counterForList);
						list.retrieveAt(pos, object);
						writeFile << object << endl;
						current = current->next;
						writeFile << "Without index: " << counterForList << " accesses" << endl;
						writeFile << "With index: " << counter - 1 << " accesses" << endl << endl;
					}

				}
				writeFile.close();

			}

			if (var2 == "MAJOR")
			{
				ofstream writeFile(txtFile.c_str());
				
				getline(readFile2, major);
				
				int counter = 0;
				
				nMajor.searchList2(index, major, counter);
				
				Node* current = index.firstPtrVar();
				
				Student object;
				
				int counterForList = 0;
				
				if (current == NULL) 
				{
					writeFile << "No record found for " << var2 << " " << major << endl;
					writeFile << "Without index: " << list.listSize() << " accesses" << endl;
					writeFile << "With index: " << counter << " accesses" << endl;
				}
				else
				{

					while (current != NULL) 
					{
						int pos = current->info;
						list.retrieveAt(pos, object);
						list.searchMajor(major, counterForList);
						writeFile << object << endl;
						current = current->next;
						writeFile << "Without index: " << counterForList << " accesses" << endl;
						writeFile << "With index: " << counter + 1 << " accesses" << endl << endl;
					}


				}
				writeFile.close();
			}

			if (var2 == "GPA")
			{

				ofstream writeFile(txtFile.c_str());
			
				getline(readFile2, conversion);
				
				GPA = stof(conversion);
				
				int counter = 0;
				
				nGPA.searchList2(index, GPA, counter); 
				
				Node* current = index.firstPtrVar();
				
				Student object;
				
				int counterForList = 0;
				
				if (current == NULL) 
				{
					writeFile << "No record found for " << var2 << " " << fixed << setprecision(2) << GPA << endl;
					writeFile << "Without index: " << list.listSize() << " accesses" << endl;
					writeFile << "With index: " << counter + 2 << " accesses" << endl;
				}
				else
				{
					while (current != NULL)
					{
						int pos = current->info;
						list.retrieveAt(pos, object);
						list.searchGPA(GPA, counterForList);
						writeFile << object << endl;
						current = current->next;
						writeFile << "Without index: " << counterForList << " accesses" << endl;
						writeFile << "With index: " << counter - 1 << " accesses" << endl << endl;
					}

				}
				writeFile.close();
			}
		}

		list.print();
	}

	readFile.close();

	return 0;
}
