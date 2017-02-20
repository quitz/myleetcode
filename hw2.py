#coding: utf-8

dic = open('fetch_nbc','r').readlines()
num = [item.split(',')[1] for item in dic if len(item.split(','))==2] + [item.split(',')[2] for item in dic if len(item.split(','))==3]
suc = num.count(200)


print 'Fetch statstics: \n'
print 'fetches attempted: ' + str(len(dic))
print '\n fetches succedded: ' + str(suc)
print '\n fetches failed: ' + str(len(dic) - suc) + '\n'

dic = open('url_nbc','r').readlines()
ud = [item for item in set(dic)]
suc = len([1 for item in ud if(item.startswith('http://www.nbcnews.com'))==True]

print 'Outgoing URLs: \n'
print 'total URLs extracted: ' + str(len(dic))
print '\n unique fotal URLs extracted: ' + str(ud)
print '\n unique URLs within a news website: ' + str(suc)
print '\n unique URLs outside the news website: ' + str(len(ud) - suc) + '\n'

dic = open('fetch_nbc','r').readlines()
num = [item.split(',')[1] for item in dic if len(item.split(','))==2] + [item.split(',')[2] for item in dic if len(item.split(','))==3]

print "Status codes: \n"
for item in set(num):
    print str(item) + ': ' + str(num.count(item)) + '\n'

dic = open('visit_nbc','r').readlines()
num1 = [item.split(',')[1] for item in dic]
num2 = [item.split(',')[3] for item in dic]

print "File size:\n"
print '<1KB' + str(len([item for item in num1 if(item<1024)]) + '\n'
print '1KB~10KB' + str(len([item for item in num1 if(item>=1024 && item<10240)]) + '\n'
print '10KB~100KB' + str(len([item for item in num1 if(item>=10240 && item<102400)]) + '\n'
print '100KB~1MB' + str(len([item for item in num1 if(item>=102400 && item<1024000)]) + '\n'
print '>1MB' + str(len([item for item in num1 if(item>=1024000)]) + '\n'

print 'Content Type:\n'
for item in set(num2):
    print str(item) + ': ' + str(num2.count(item)) + '\n'


