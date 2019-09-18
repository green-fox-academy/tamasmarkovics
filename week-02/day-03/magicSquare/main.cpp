#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    int v1 = s[0][0] + s[0][1] + s[0][2];
    int v2 = s[1][0] + s[1][1] + s[1][2];
    int v3 = s[2][0] + s[2][1] + s[2][2];
    int h1 = s[0][0] + s[1][0] + s[2][0];
    int h2 = s[0][1] + s[1][1] + s[2][1];
    int h3 = s[0][2] + s[1][2] + s[2][2];

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //int result = formingMagicSquare(s);

    //fout << result << "\n";

    //fout.close();

    vector<int> sumV(3);
    vector<int> sumH(3);

    for (int i = 0; i < 3; i++) {
        int tempH = 0;
        int temp = 0;
        for (int j = 0; j < 3; ++j) {
            temp += s[i][j];
            tempH += s[j][i];
        }
        sumV[i] = temp;
        sumH[i] = tempH;
    }

    for (int k = 0; k < 3; ++k) {
        cout << sumV[k] << endl;
    }
    for (int k = 0; k < 3; ++k) {
        cout << sumH[k] << endl;
    }

    //LATEEEEER

    return 0;
}
