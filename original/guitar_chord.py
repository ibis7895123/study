# -*- coding: utf-8 -*-
"""
Created on Sat Nov 10 19:13:48 2018

@author: 斗城
"""

class Chord:
    onkaiSharp = ["C","C#","D","D#","E","F","F#","G","G#","A","A#","B"]
    onkaiFlat = ["C","Db","D","Eb","E","F","Gb","G","Ab","A","Bb","B"]
                  
    def __init__(self, start, chousei):
        self.start = start
        if start == "E#":
            self.start = "F"
            print("Key=Fで出力")
        elif start == "B#":
            self.start = "C"
            print("Key=Cで出力")
        elif start == "Fb":
            self.start = "E"
            print("Key=Eで出力")
        elif start == "Cb":
            self.start = "B"
            print("Key=Bで出力")
        
        self.chousei = chousei
        self.major = "△"
        self.minor = "m"
        self.seventh = "7"
        self.flatFive = "(-5)"
        #self.onkai = Chord.onkaiSharp
        
        if ("#" in self.start):
            self.onkai = Chord.onkaiSharp
        elif ("b" in self.start):
            self.onkai = Chord.onkaiFlat
        elif(self.chousei == "major"):
            self.onkai = Chord.onkaiSharp
        else:
            self.onkai = Chord.onkaiFlat
        self.start_num = self.get_start_num()
        
        
    def get_start_num(self):
        for i, root in enumerate(self.onkai):
            if self.start == root:
                return i
    
    def chordIndex(self, root, num):
        if root + num < 12:
            return root + num
        else:
            return root + num -12
    
    def chordTone(self, chord):
        #コードトーンインデックスの生成
        chordToneIndex = []
        chordToneIndex.append(chord)
        chordToneIndex.append(self.chordIndex(chord,4))
        chordToneIndex.append(self.chordIndex(chord,7))
        #print(chordToneIndex)
        
        return chordToneIndex
    
    def getRootTone(self, index):
        #ルート代入
        rootToneList = [self.onkai[index[i]]\
                        for i in range(len(index))]
        #print(7,rootToneList)
        
        #同じルートあるか
        doubleOnkaiIndex = []
        doubleIndex = []
        lostOnkaiIndex = []
        #rootToneListのアルファベットの数を計算
        for j, o in enumerate(self.onkai):
            temp = [i for i, root in enumerate(rootToneList)\
                    if list(root)[0] == o]
            #print(j,temp)
            
            #2個以上あるものはインデックスをdoubleIndexへ
            #アルファベットの音階インデックスをdoubleOnkaiIndexへ
            #使われてないアルファベットの音階インデックスをlostOnkaiIndexへ
            if len(temp) > 1:
                for i in temp:
                    doubleIndex.append(i)
                    doubleOnkaiIndex.append(index[i])
                    
            if len(temp) == 0 and len(o) < 2:
                lostOnkaiIndex.append(j)
                
        #print(2,doubleIndex)
        #print(3,doubleOnkaiIndex)
        #print(4,lostOnkaiIndex)
        
        #重複なければrootToneList返す
        if len(doubleIndex) == 0:
            #print(100,rootToneList)
            return rootToneList
        
        else:
            #lostOnkaiIndexに一番近いdoubleOnkaiIndex取得
            henkouIndex = []
            for lost in lostOnkaiIndex:
                temp = [i for i,x in enumerate(doubleOnkaiIndex) if abs(x - lost) == 1]
                if len(temp) == 0:
                    temp = [i for i,x in enumerate(doubleOnkaiIndex) if abs(x + 12 - lost) == 1]
                if len(temp) == 0:
                    temp = [i for i,x in enumerate(doubleOnkaiIndex) if abs(x - 12 - lost) == 1]
                #print(5,temp)
                if len(temp) == 0:
                    return rootToneList
                else:
                    #print(5,temp)
                    henkouIndex.append(doubleIndex[temp[0]])
                    #print(6,henkouIndex)
                    
            #rootToneListを変更
            for i in range(len(henkouIndex)):
                temp = lostOnkaiIndex[i] - index[henkouIndex[i]]
                if temp == -11:
                    temp += 12
                elif temp == 11:
                    temp -= 12    
                #print(8,temp)
                
                if temp > 0:
                    rootToneList[henkouIndex[i]] =\
                    self.onkai[lostOnkaiIndex[i]] + "b" * abs(temp)
                else:
                    rootToneList[henkouIndex[i]] =\
                    self.onkai[lostOnkaiIndex[i]] + "#" * abs(temp)
        
            if rootToneList[0] != self.start:
                rootToneList[0] = self.start
            
            #print(101,rootToneList)
            return rootToneList
        
        
    def diatonic(self):
        #ダイアトニックインデックスの生成
        diatonicIndex = []
        if (chousei == "major"):
            diatonicIndex.append(self.start_num)
            diatonicIndex.append(self.chordIndex(self.start_num,2))
            diatonicIndex.append(self.chordIndex(self.start_num,4))
            diatonicIndex.append(self.chordIndex(self.start_num,5))
            diatonicIndex.append(self.chordIndex(self.start_num,7))
            diatonicIndex.append(self.chordIndex(self.start_num,9))
            diatonicIndex.append(self.chordIndex(self.start_num,11))
        else:
            diatonicIndex.append(self.start_num)
            diatonicIndex.append(self.chordIndex(self.start_num,2))
            diatonicIndex.append(self.chordIndex(self.start_num,3))
            diatonicIndex.append(self.chordIndex(self.start_num,5))
            diatonicIndex.append(self.chordIndex(self.start_num,7))
            diatonicIndex.append(self.chordIndex(self.start_num,8))
            diatonicIndex.append(self.chordIndex(self.start_num,10))
            
        #print(1,diatonicIndex)
        
        #ルート音リストの生成
        rootToneList = self.getRootTone(diatonicIndex)
        
        #コードネーム格納
        self.chordOut = []
        
        if (self.chousei == "major"):
            self.chordOut.append(rootToneList[0] + self.major)
            self.chordOut.append(rootToneList[1] + self.minor)
            self.chordOut.append(rootToneList[2] + self.minor)
            self.chordOut.append(rootToneList[3] + self.major)
            self.chordOut.append(rootToneList[4] + self.seventh)
            self.chordOut.append(rootToneList[5] + self.minor)
            self.chordOut.append(rootToneList[6] + self.minor + self.seventh + self.flatFive)
        else:
            self.chordOut.append(rootToneList[0] + self.minor)
            self.chordOut.append(rootToneList[1] + self.minor + self.seventh + self.flatFive)
            self.chordOut.append(rootToneList[2] + self.major)
            self.chordOut.append(rootToneList[3] + self.minor)
            self.chordOut.append(rootToneList[4] + self.minor)
            self.chordOut.append(rootToneList[5] + self.major)
            self.chordOut.append(rootToneList[6] + self.seventh)
        
        print(self.chordOut)
        
        
start = "B#"
chousei = "major"
print("Key:" + str(start) + ", 調:" + str(chousei))

chord1 = Chord(start,chousei)
chord1.diatonic()

