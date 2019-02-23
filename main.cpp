#include <iostream>
#include <vector>
using namespace std;

class spans{
public:
    vector<int>::const_iterator begin;
    vector<int>::const_iterator end;
    int size;

    spans(vector<int>::const_iterator start, vector<int>::const_iterator end){
        this->begin = start;
        this->end = end;
        size = (end-start);
    }

    void print(){
        cout << "size:  " << size << endl;
        vector<int>::const_iterator walker = begin;

        for (int i=0; i< size; i++){
            cout << *walker << "\t";
            walker++;
        }
    }
};

int longest_balanced_span(const std::vector<int>& values){
    int best = 0;
    int currentCount = 0;
    int size = values.size();
    int valA = 0;
    vector<int>::const_iterator upper;
    vector<int>::const_iterator lower;
    vector<int>::const_iterator walker = values.begin();


    for (int i=0; i< size; i++){
        valA += values.at(i);
        for (int j = i+1; j< size; j++){
            valA+=values.at(j);
            if (valA == 0 && (j+1 - i) > best){
//                cout << "i\t" << i << "\t" << "j\t" << j << endl;
                best = (j+1-i);
                upper = walker + j;
                lower = walker + i;

            }
        }
    }

    return best;
}

std::vector<int>::const_iterator find_dip(const std::vector<int>& values) {
    // TODO: Rewrite the body of this function so that it actually works. That
    // includes rewriting the return statement. After you do that, delete this
    // comment.

    vector<int>::const_iterator it;
    it = values.begin();
    int size = values.size();
    int a,b,c;                  //AbC where 'A' and 'C' should be equal and the 'b' should be the dip.
    int index = -1;

    if (size<3 && size>1){
        return values.begin();
    }


    cout << size << endl;
    for (int i=0; i< size-2; i++){
        a = values.at(i);
        b = values.at(i+1);
        c = values.at(i+2);

        //comparing if A & C are equal and that b is smaller than A & C
        if (a==c && b<a){
            index = i;      //saving the index of start of the dip
        }
    }

    if (index!=-1){
        it += index;
        return it;
    }

    else {

        return values.end();
    }
}


int main()
{
    vector<int>::const_iterator it;
    vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(-5);
    v.push_back(-3);
    v.push_back(2);
    v.push_back(-2);
    v.push_back(10);
    v.push_back(-2);
    v.push_back(-2);
    v.push_back(-2);
    v.push_back(-2);
    v.push_back(-2);


//    it = find_dip(v);
    cout << longest_balanced_span(v);

//    cout << *it;
}
