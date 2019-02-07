#include <algorithm/neuralNetworks/FullyConnectedNeuralNetwork.h>
using namespace std;

vector<VectorXd> makeTrainData(unsigned int num,unsigned int inSize,double startNum,double endNum){
    vector<VectorXd> ret(0);
    ret.reserve(num);
    for(unsigned int i=0;i<num;++i){
        ret.emplace_back(VectorXd(inSize).unaryExpr([startNum,endNum](double dump){ return random_evenly_distributed(startNum,endNum);}));
    }
    return ret;
}
vector<VectorXd> makeAnswer(vector<VectorXd>& trainData, unsigned int outSize){
    vector<VectorXd> ret(0);
    ret.reserve(trainData.size());
    for(unsigned int i=0;i<trainData.size();++i){
        auto &item = trainData.at(i);
        ret.emplace_back(VectorXd(outSize));
        //单层感知器
        //ret.at(i) << (1 / (1 + pow(E, -(item(0)+item(1))))) ;
        /**分类器**/
        //在线上+,在线下- (一维)
        ret.at(i) << ((item(0)+item(1))>0 ? 1.0 : 0.0);

        //交叉线(二维) y=-x y=x 左右- 上下+
        //ret.at(i) << ( (item(0)+item(1)<0 && item(1)-item(0)>0)||(item(0)+item(1)>0 && item(1)-item(0)<0) ? 1.0 : 0.0);

        //在圆内(多维)
        //ret.at(i) << (pow(item(0), 2) + pow(item(1), 2) <= 1 ? 1.0 : 0.0);
    }
    return ret;

}

int main() {
    unsigned int inp_hid_oup[]={2,2,1};
    unsigned int totalFloors = 3;

    auto tarinData=makeTrainData(100,inp_hid_oup[0],-6,6);
    auto tarinAnswer=makeAnswer(tarinData,inp_hid_oup[totalFloors-1]);

    FullyConnectedNeuralNetwork connect(inp_hid_oup,totalFloors,-2.0,2.0);
    connect.train(tarinData, tarinAnswer, 2, 10000, 0.1);
    cout<<"enter:\n"<<tarinData.at(0)<<"\nexport\n"<<connect.prediction(tarinData.at(0))<<endl;
    cout<<"standardOutput:\n"<<tarinAnswer.at(0)<<endl;
    return 0;
}


//int main() {
//    std::ofstream myfile("D:\\1.txt",std::ios::out|std::ios::trunc);
//    myfile<<"白纸人生"<<std::endl<<"网址："<<"www.cppblog.com/andxie99"<<std::endl;
//    myfile.close();
//    system("pause");
//}
