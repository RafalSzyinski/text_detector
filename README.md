
### Deep Neural Network (DNN)
Deep nets process data in complex ways by employing sophisticated math modeling.
A neural network consists of several connected units called nodes.
These are the smallest part of the neural network and act as the neurons in the human brain. 
When a neuron receives a signal, it triggers a process. 
The signal is passed from one neuron to another based on input received. 
A complex network is formed that learns from feedback.
The nodes are grouped into layers. 
A task is solved by processing the various layers between the input and output layers. 
The greater the number of layers to be processed, the deeper the network, therefore the term, deep learning.

<p align="center">  
  <img src="/images/DNN.png">
</p>

#### FaceDetectorDNN

The program uses the caffe model as a neural network, which consists of two files: 
* [deloy.prototxt](assets/deploy.prototxt) - which describes the model archtecture
* [res10_300x300_ssd_iter_140000_fp16.caffemodel](assets/res10_300x300_ssd_iter_140000_fp16.caffemodel) - is the binary data for the model weights.

<p align="center">  
  <img src="/images/ExampleDNN.png">
</p>

### Links

The program was created on the basis of: 
* https://github.com/bewagner/visuals/tree/blog-post-1
