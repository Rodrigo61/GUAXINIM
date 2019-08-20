/*
 * Podemos encontrar quantos elementos X existem num intervalor L-R em
 * tempo LG se esse interva-lo for estático e X <= 10^6.
 * Basta guardar cada indice que cada numero foi encontrado (usando um
 * vetor de vetores) e dps só fazer busca binaria
 * */
 
for (int i = 0; i < N; i++)
{
	scanf("%d", &vals[i]);
	idxs[vals[i]].pb(i);
}
upper_bound(all(idxs[target]), r) - lower_bound(all(idxs[target]), l);
