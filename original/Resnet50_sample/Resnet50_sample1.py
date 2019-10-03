# -*- coding: utf-8 -*-
"""
Created on Fri Feb 15 17:37:42 2019

"""

import glob
import os

from keras.applications.resnet50 import ResNet50
from keras.preprocessing import image
from keras.preprocessing.image import load_img, img_to_array
from keras.applications.resnet50 import preprocess_input, decode_predictions
import numpy as np
import json
import matplotlib.pyplot, pylab as plt

#初期パラメータ
img_size = 224   #画像サイズ


def resnet_Predict(dir_file):
    
    img = load_img(dir_file, target_size=(img_size, img_size))
    #plt.imshow(image)
    
    x = image.img_to_array(img)
    #(Height, Wigth, Channel)→(1, Height, Wigth, Channel)に変更 ResNet50の入力形式
    x = np.expand_dims(x, axis=0)
    #前処理
    x = preprocess_input(x)        

    #推論結果
    preds = model.predict(x)[0]
    #Top3抽出
    index_top3 = preds.argsort()[-3:][::-1]
    #print(preds_top3)
    
    #入力画像表示
    plt.axis('off')
    plt.imshow(img)
    plt.show()
    #推論結果表示
    print('Predicted:')
    #for _, pred, percent in decode_predictions(preds, top=3):
    for pred, percent in zip(names[index_top3], preds[index_top3]):
        print("{0}: {1:.1%}".format(pred, percent))



#ImageNetラベル一覧読込み(ImageNetラベルの日本語化)
with open('imagenet_class_index.json', encoding='utf-8') as f:
    data = json.load(f)
    names = np.array([row['ja'] for row in data])
    

#学習済モデル読み込み
model = ResNet50(weights='imagenet')


#画像フォルダ名取得
dir_img = "./image"
#dir_folders = os.listdir(dir_img)
#print(dir_folders)

#画像データ取得
x = []
#画像ファイルパス生成
dir_files = glob.glob(dir_img + "/*.jpg")
#print(dir_files)

#推論
for dir_file in dir_files:
    resnet_Predict(dir_file)
