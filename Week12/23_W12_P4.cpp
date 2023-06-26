//23_W12_P4

#include <iostream>

#define NOEXIST 0
#define ABSENT 1
#define PRESENT 2
#define AVAILABLE 3 //삭제 된 경우 ->검색할 때 넘어가기 위함.

int presentNum = 0; //출석 학생 수

using namespace std;

struct Student {
    int id;
    int cLass;
    string name;
    int valid;

    Student() {
        id = 0;
        cLass = 0;
        name = "";
        valid = NOEXIST;
    }

    Student(int _valid) {
        id = 0;
        cLass = 0;
        name = "";
        valid = _valid;
    }

    Student(int _id, int _cLass, string _name) {
        id = _id;
        cLass = _cLass;
        name = _name;
        valid = ABSENT;
    }

};

class HashTable {
public:

    Student* AttendanceForId;
    Student* AttendanceForName;

    int capacity = 800000;

    HashTable() {
        AttendanceForId = new Student[800000];
        AttendanceForName = new Student[800000];
    }

    int strToInt(string name) {
        int intNum = 0;

        for (int i = 0; i < 6; i++) {
            int twentySix = 1;
            for (int j = 0; j < i; j++) {
                twentySix *= 26;
            }

            intNum += ((int)name[i] - 97) * twentySix;
        }
        return intNum;
    }

    int hashFunc(int idInt) {
        return idInt % capacity;
    }

    void Add(int _id, int _cLass, string _name) {
        int indexForName = hashFunc(strToInt(_name));
        int indexForId = hashFunc(_id);

        while (AttendanceForName[indexForName].valid != NOEXIST && AttendanceForName[indexForName].valid != AVAILABLE) {
            indexForName = hashFunc(indexForName + 1);
        }
        while (AttendanceForId[indexForId].valid != NOEXIST && AttendanceForName[indexForName].valid != AVAILABLE) {
            indexForId = hashFunc(indexForId + 1);
        }

        Student student(_id, _cLass, _name);
        AttendanceForName[indexForName] = student;
        AttendanceForId[indexForId] = student;
    }
       
    void Delete(int _id) {
        int indexForId = hashFunc(_id);

        while (AttendanceForId[indexForId].id != _id) {
            indexForId = hashFunc(indexForId + 1);
        }

        string _name = AttendanceForId[indexForId].name;
        int indexForName = hashFunc(strToInt(_name));
        while (AttendanceForName[indexForName].name != _name) {
            indexForName = hashFunc(indexForName + 1);
        }

        cout << AttendanceForId[indexForId].name << " " << AttendanceForId[indexForId].cLass << "\n";

        if (AttendanceForId[indexForId].valid == PRESENT) {
            presentNum--;
        }

        Student student(AVAILABLE);
        AttendanceForId[indexForId] = student;
        AttendanceForName[indexForName] = student;
        
    }

    void Name(int _id) {
        int indexForId = hashFunc(_id);

        while (AttendanceForId[indexForId].id != _id) {
            indexForId = hashFunc(indexForId + 1);
        }

        cout << AttendanceForId[indexForId].name << "\n";
    }

    void Change(int _id, int _cLass) {
        int indexForId = hashFunc(_id);

        while (AttendanceForId[indexForId].id != _id) {
            indexForId = hashFunc(indexForId + 1);
        }

        string _name = AttendanceForId[indexForId].name;
        int indexForName = hashFunc(strToInt(_name));
        while (AttendanceForName[indexForName].name != _name) {
            indexForName = hashFunc(indexForName + 1);
        }

        AttendanceForId[indexForId].cLass = _cLass;
        AttendanceForName[indexForName].cLass = _cLass;
    }

    void Present(string _name) {
        int indexForName = hashFunc(strToInt(_name));

        while (AttendanceForName[indexForName].name != _name && AttendanceForName[indexForName].valid!=NOEXIST) {
            indexForName = hashFunc(indexForName + 1);
        }

        if (AttendanceForName[indexForName].valid == NOEXIST) {
            cout << "Invalid\n";
            return;
        }

        int indexForId = hashFunc(AttendanceForName[indexForName].id);
        while (AttendanceForId[indexForId].name != _name) {
            indexForId = hashFunc(indexForId + 1);
        }

        if (AttendanceForName[indexForName].valid == ABSENT) {
            presentNum++;
        }
        AttendanceForName[indexForName].valid = PRESENT;
        AttendanceForId[indexForId].valid = PRESENT;
        cout << AttendanceForName[indexForName].id << " " << AttendanceForName[indexForName].cLass << "\n";
        
    }

    void Absent(string _name) {
        int indexForName = hashFunc(strToInt(_name));

        while (AttendanceForName[indexForName].name != _name && AttendanceForName[indexForName].valid != NOEXIST) {
            indexForName = hashFunc(indexForName + 1);
        }

        if (AttendanceForName[indexForName].valid == NOEXIST) {
            cout << "Invalid\n";
            return;
        }

        int indexForId = hashFunc(AttendanceForName[indexForName].id);
        while (AttendanceForId[indexForId].name != _name) {
            indexForId = hashFunc(indexForId + 1);
        }

        if (AttendanceForName[indexForName].valid == PRESENT) {
            presentNum--;
        }
        AttendanceForName[indexForName].valid = ABSENT;
        AttendanceForId[indexForId].valid = ABSENT;
        cout << AttendanceForName[indexForName].id << " " << AttendanceForName[indexForName].cLass << "\n";
    }

};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    HashTable hashTable;

    int numOfTest;
    cin >> numOfTest;

    while (numOfTest--) {
        string cmd;
        cin >> cmd;

        int _id, _cLass;
        string _name;

        if (cmd == "add") {
            cin >> _id >> _cLass >> _name;
            hashTable.Add(_id, _cLass, _name);
        }
        else if (cmd == "delete") {
            cin >> _id;
            hashTable.Delete(_id);
        }
        else if (cmd == "name") {
            cin >> _id;
            hashTable.Name(_id);
        }
        else if (cmd == "change") {
            cin >> _id >> _cLass;
            hashTable.Change(_id, _cLass);
        }
        else if (cmd == "present") {
            cin >> _name;
            hashTable.Present(_name);
        }
        else if (cmd == "absent") {
            cin >> _name;
            hashTable.Absent(_name);
        }
    }
    cout << presentNum;
}

