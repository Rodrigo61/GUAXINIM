texto = ['balavra1', 'aalavra2', 'palavra1', 'palavra3', 'dsfas']
dict_freq = {}

for palavra in texto:
    dict_freq[palavra] = 0

for palavra in texto:
    dict_freq[palavra] = dict_freq[palavra] + 1

for key in sorted(dict_freq):
    print(key,":",dict_freq[key])