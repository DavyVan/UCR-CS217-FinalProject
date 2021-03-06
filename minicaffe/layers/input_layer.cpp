//
// Created by mingchen on 3/2/19.
//

#include "input_layer.h"
#include <assert.h>
#include <cstring>
InputLayer::InputLayer(char *name):Layer(name) {

}

void InputLayer::infer(vector<Blob*> lefts, vector<Blob*> rights) {
    assert(lefts.size()==2);
    assert(rights.size()==2);
    for(int i=0;i<lefts.size();i++){
        memcpy(rights[i]->_data,lefts[i]->_data,lefts[i]->sizeofEle*lefts[i]->get_ele_num());
    }

}
void InputLayer::bp(vector<Blob *> lefts, vector<Blob *> rights) {

}

void InputLayer::get_outputs_dimensions(int *inputs_dims, const int numInputs, int *outputs_dims,
                                        const int numOutputs) {

    // memcpy(outputs_dims, inputs_dims, 4 * sizeof(int)*numOutputs);
    outputs_dims[0] = SeqNet::get_batchsize();
    outputs_dims[1] = 28;
    outputs_dims[2] = 28;
    outputs_dims[3] = 1;
    outputs_dims[4] = SeqNet::get_batchsize();
    outputs_dims[5] = 10;
    outputs_dims[6] = outputs_dims[7] = 1;

}
bool InputLayer::check_dimensions() {
    return 1;
}
int InputLayer::init() {
    return 0;
}

void InputLayer::infer_gpu(vector<Blob *> lefts, vector<Blob *> rights)
{
    infer(lefts, rights);
}
void InputLayer::bp_gpu(vector<Blob *> lefts, vector<Blob *> rights)
{
    bp(lefts, rights);
}
