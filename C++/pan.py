

class Citizen:
    def __init__(self,citizenId,citizenName,citizenAge,profession,isWarrior,city):
        self.citizenId = citizenId
        self.citizenName = citizenName
        self.citizenAge = citizenAge
        self.profession = profession
        self.isWarrior = isWarrior
        self.city = city
    
    
class HealthCenter:
    
    def getHighestCity(self,Citizens):
        dis = {}
        dis2 = {}
        for obj in Citizens:
            if obj.city not in dis:
                if obj.isWarrior:
                    dis[obj.city] =  1
            else:
                if obj.isWarrior:
                    dis[obj.city] += 1
            
            if obj.city not in dis2:
                if obj.citizenAge >= 60:
                    dis2[obj.city] =  1
            else:
                if obj.citizenAge >= 60:
                    dis2[obj.city] += 1
        
        print(dis,dis2) 
                
        cityForm = ""
        countWarrior = 0
        for city in dis:
            if dis[city] > countWarrior:
                cityForm = city
                countWarrior = dis[city]
                                
        citty = ""
        countCitizen = 0
        for city in dis2:
            if dis2[city] > countCitizen:
                citty = city
                countCitizen = dis2[city]
        
        return [(cityForm,countWarrior),(citty,countCitizen)]

    def CityWiseRequirement(self,Citizens):
        dis = {}
        for obj in Citizens:
            if obj.city not in dis:
                dis[obj.city] = [0,0]
            if obj.isWarrior:
                dis[obj.city][0] += 1
        
            if obj.citizenAge >= 60:
                dis[obj.city][1] += 1
                    
        
        return dis
    
    
if __name__ == "__main__":
    
    Citizens = []  
    for i in range(int(input())):
        id = int(input())
        name = input()
        age = int(input())
        job = input()
        warrior = input()
        if("True" == warrior):
            warrior =True
        else:
            warrior = False
        city = input()
        citiz = Citizen(id,name,age,job,warrior,city)
        Citizens.append(citiz)
    
    hc = HealthCenter()
    (cityForm,countWarrior),(citty,countCitizen) =hc.getHighestCity(Citizens)
    print({cityForm:countWarrior})
    print({citty:countCitizen})
    dis = hc.CityWiseRequirement(Citizens)
    srt=sorted(dis.keys(), key=lambda x:x.lower())
    for key in srt:
        print(key,dis[key])
    
    
        
# 10
# 1
# j
# 43
# Doc
# True
# Hy
# 2
# r
# 63
# r
# False
# Hy
# 3
# N
# 45
# p
# True
# Hy
# 4
# Vi
# 23
# s
# False
# Hy
# 5
# k
# 72
# p
# False
# Hy
# 6
# Nitin
# 22
# s
# False
# Chen
# 7
# S
# 28
# p
# True
# Chen
# 8
# m
# 68
# r
# False
# Chen
# 9
# r
# 68
# r
# False
# Dehli
# 10
# r
# 23
# s
# False
# Dehli