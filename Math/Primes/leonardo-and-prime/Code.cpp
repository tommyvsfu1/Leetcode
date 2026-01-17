#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'primeCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

int primeCount(long n) {
    vector<int> primes(1000, 1);
    
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i * i < 1000; i++) {
        int j = i * i;
        while (j < 1000) {
            primes[j] = 0;
            j+=i;
        }
    }
    
    vector<int> p;
    for (int i = 0; i < 1000; i++) {
        if (primes[i] == 1) p.push_back(i);
    }
    
    vector<unsigned long long> mul;
    unsigned long long pre = 1;
    for (int i = 0; i < p.size(); i++) {
        pre = pre * (unsigned long long)p[i];
        if (pre > (unsigned long long)(1e18)) break;
        mul.push_back(pre);
    }
    int res = 0;
    for (int i = 0; i < mul.size(); i++) {
        if (n < mul[i]) {
            break;
        }
        res++;
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        int result = primeCount(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
