# Proje-son-hali
Bu projede amaç silah atıcısının atış doğruluğunu arttırmaktı. Bu hedefi parametreleri özelleştirilmiş makine öğrenmesi modeli oluşturup gerçekleştirdik. Model vücuda takılı olan 2 adet IMU sensörden aldığı veriler ile beslenmekte. Sistem gerçek zamanlı olarak bir adet esp32 kart üstünde çalışmakta. 

****main.py dosyası makine öğrenmesi modelini C koduna dönüştürür****
****csc dosyası sistemin bacakta olan esp'sinde çalışan koddur***
***rass_rd dosyası sistemin dürbünde olan esp'sinde çalışan koddur***


#End-Version-of-The-Project
We achieved this goal by creating a customized machine learning model with parameters. The model is fed with the data it receives from 2 IMU sensors attached to the body. The system works in real time on an esp32 card. 
****main.py file converts machine learning model to C code****
****csc file is the code that runs on the shooter's leg esp***
***rass_rd file is the code that runs in the shooter's binocular esp*** 
