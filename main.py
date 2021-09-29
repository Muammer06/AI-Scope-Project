from micromlgen import port
from sklearn.tree import DecisionTreeClassifier
from sklearn.multioutput import MultiOutputRegressor
from sklearn.tree import DecisionTreeRegressor
from sklearn.ensemble import GradientBoostingRegressor
import numpy as np

import matplotlib.pyplot as plt # data visualization
import seaborn as sns # statistical data visualization


from sklearn.metrics import accuracy_score
from sklearn.preprocessing import MinMaxScaler

hepsi_giris=np.array([[-145.50,-0.50,-171.50,80.45,84.33,-117.44],[-157.44,1.67,-173.90,74.80,41.67,-81.91],[-140.26,1.01,-171.19,-41,75.52,106.82],[-127.57,-1.31,-171.12,3.90,69.59,144.56],[-149.70,17.14,-169.23,-20.50,72.80,131.35],[-157.61,30.77,-174.48,79.13,58.40,-100.99],[-116.56,-22.14,-166.15,105.39,60.19,-72.55],[-145.87,0.72,-171.19,74.43,45.74,-85.17],[167.46,0.74,-179.40,44.14,-17.21,-83.89],[-168.92,28.62,-177.36,45.83,42.41,-146.40],[163,1,179,-152,-81,119],[160,2,179,-101,-82,55],[170,8,-178,-2,-74,-46],[157,1,179,-132,-5,122],[164,4,-179,-108,13,127],[164,24,-176,7,-82,-54],[150,-20,-170,57,-81,-104],[144,5,179,-55,40,114],[161,24,-178,-72,-79,25],[112,-30,-177,-158,-82,109]])
hepsi_cikis_X=np.array([[-25],[-46],[-43],[-20],[62],[9],[-60],[-11],[-57],[-39],[-9],[-67],[-21],[-15],[8],[-17],[-3],[-22],[6],[-43]])
hepsi_cikis_Y=np.array([[59],[12],[48],[65],[49],[31],[10],[35],[104],[72],[16],[16],[5],[17],[16],[17],[-3],[10],[32],[-2]])


from sklearn import tree
import graphviz


clf=DecisionTreeClassifier(criterion='entropy',
                           max_depth=6, random_state=10,
                           splitter="best",max_features="log2",
                           min_samples_leaf=1)
model=clf.fit(hepsi_giris, hepsi_cikis_X)

text_representation = tree.export_text(clf)
print(text_representation)
print(port(model))
