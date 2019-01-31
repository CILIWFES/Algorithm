
#include "algorithm\neuralNetworks\base.h"


using namespace std;

int main(){
    MatrixXd& kk=*new MatrixXd(4,4);
    ArrayXd& arr=*new ArrayXd(8);
    kk.array()=arr;

    cout<< kk;
    cout<< kk.rows();
    cout<< kk.cols();
}
void main1() {
    unsigned size= 10*10;
    double *arr = new double[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    double *arr2 = new double[size];
    for (int i = 0; i < size; i++) {
        arr2[i] = i+1;
    }
    unsigned int sqr = (unsigned int)sqrt(size);
    MatrixXd m = MatrixXd::Map(arr, sqr, sqr);
    MatrixXd m2 = MatrixXd::Map(arr2, sqr, sqr);


    int time=10000;
    double sum;
    timePoint.setPoint();
    for(int i=0;i<time;i++){
        sum=(m*m2).sum();
    }
    cout << "sum:" << endl << sum<< endl;
    timePoint.showPoint();

    timePoint.setPoint();
    for(int i=0;i<time;i++){
        sum=0;
        for(int j=0;j<size;j++){
            for(int k=0;k<sqr;k++){
                sum+=arr[j]*arr2[j/sqr+k*sqr];
            }
        }
    }
    cout << "sum:"  << sum<< endl;
    timePoint.showPoint();

}
//
//int test1() {
//    int trainInt = 10;
//    vector<vector<double> *> *trainDatas = new vector<vector<double> *>(0);
//    trainDatas->reserve(2 * trainInt * 2 * trainInt);
//    vector<vector<double> *> *trainAnswers = new vector<vector<double> *>(0);
//    trainAnswers->reserve(2 * trainInt * 2 * trainInt);
//
//    for (double i = -trainInt; i < trainInt; i += 1) {
//
//        for (double j = -trainInt; j < trainInt; j += 1) {
//            trainDatas->push_back(new vector<double>{i * 1.0, j * 1.0});
//            trainAnswers->push_back(new vector<double>{i >= 0 ? (j >= 0 ? 1.0 : 0.0) : (j < 0 ? 1.0 : 0.0)});
//        }
//    }
////    trainDatas->push_back(new vector<double>{0,1});
////    trainDatas->push_back(new vector<double>{1,0});
////    trainDatas->push_back(new vector<double>{1,1});
////    trainDatas->push_back(new vector<double>{0,0});
////    trainAnswers->push_back(new vector<double>{0});
////    trainAnswers->push_back(new vector<double>{0});
////    trainAnswers->push_back(new vector<double>{1});
////    trainAnswers->push_back(new vector<double>{1});
//
//    unsigned inp_hid_out[] = {2, 4, 2, 1};
//    auto trainTemp = fullyConnected::makeSet(*trainDatas, *trainAnswers);
//    delete trainDatas;
//    delete trainAnswers;
//
//    int randRange[] = {-2, 2};
//    auto fullyConnected = fullyConnected::makeFullyConnected(5000, 1, inp_hid_out, 4, trainTemp, randRange, 0);
//
//    auto *temp = new vector<double>({-8, 5});
//    shared_ptr<vector<double>> ret(fullyConnected->prediction(*temp));
//    cout << "prediction \t";
//    for (unsigned i = 0; i < ret->size(); i++) {
//        if (i == ret->size() - 1) {
//            cout << ret->at(i) << "\t"
//                 << (temp->at(0) >= 0 ? (temp->at(1) >= 0 ? 1.0 : 0.0) : (temp->at(1) < 0 ? 1.0 : 0.0)) << endl;
//        } else {
//            cout << ret->at(i) << "\t";
//        }
//    }
//
//    temp = new vector<double>({-6, -1});
//    shared_ptr<vector<double>> ret1(fullyConnected->prediction(*temp));
//    cout << "prediction \t";
//    for (unsigned i = 0; i < ret1->size(); i++) {
//        if (i == ret1->size() - 1) {
//            cout << ret1->at(i) << "\t"
//                 << (temp->at(0) >= 0 ? (temp->at(1) >= 0 ? 1.0 : 0.0) : (temp->at(1) < 0 ? 1.0 : 0.0)) << endl;
//        } else {
//            cout << ret1->at(i) << "\t";
//        }
//    }
//    delete temp;
//    return 0;
//}
//int main() {
//    std::ofstream myfile("D:\\1.txt",std::ios::out|std::ios::trunc);
//    myfile<<"白纸人生"<<std::endl<<"网址："<<"www.cppblog.com/andxie99"<<std::endl;
//    myfile.close();
//    system("pause");
//}
