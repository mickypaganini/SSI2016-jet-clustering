# SSI2016-jet-clustering
### - Improving jet clustering using different unsupervised learning algorithms - 

The different clustering algorithms are currently stored in files named `<algorithm>.py`. 
These rely on data that is generated either through scikit-learn's `make_blobs` or our generator in the JetGenerator folder. The `read_data` module can be used to interface with the `.txt` file in the JetGenerator folder.

For example, to run <i>AffinityPropagation</i>, you can run one of the following commands:
* `python af.py` uses make_blobs to randomly generate data
* `python af.py --readin` reads in data from the JetGenerator (defaults to event 2)
* `python af.py --readin --event 5` reads in data from the JetGenerator and allows you to specify the event (in this case 5)

To-do:
1) Nicely split up data reading, clustering, and plotting
2) Check IRC safe
