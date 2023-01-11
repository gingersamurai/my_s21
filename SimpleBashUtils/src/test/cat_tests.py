import os

goodEx = 'cat'
badEx = '../cat/s21_cat'

flags = ['-b', '-e', '-n', '-s', '-t', '-v']

testNum = 0
successCnt = 0
failCnt = 0

for curFile in os.listdir('files'):
    for f1 in range(len(flags)):
        for f2 in range(f1 + 1, len(flags)):
            for f3 in range(f2 + 1, len(flags)):
                testNum += 1
                curFlags = f'{flags[f1]} {flags[f2]} {flags[f3]}'
                goodStr = f'{goodEx} {curFlags} files/{curFile} > good.out'
                badStr = f'{badEx} {curFlags} files/{curFile} > bad.out'
                os.system(goodStr)
                os.system(badStr)

                with open('good.out') as f:
                    goodRes = f.read()
                
                with open('bad.out') as f:
                    badRes = f.read()
                
                print(f"TEST {testNum} ", end='')
                if goodRes != badRes:
                    print('FAIL', end='')
                    failCnt += 1
                else:
                    print('SUCCESS', end='')
                    successCnt += 1
                print('\t', goodStr)

print('-'*10)
print(f'succes:\t{successCnt}/{testNum}\t{round(successCnt/testNum * 100)}%' )
print(f'fail:\t{failCnt} / {testNum}\t{round(successCnt/testNum * 100)}%')
print('-'*10)

os.system('rf -f bad.out good.out')