#include "libft.h"

// "Rnpu cebwrpg va gur 42 Pbzzba Pber pbagnvaf na rapbqrq uvag. Sbe rnpu"
// "pvepyr, bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbe gur"
// "arkg pvepyr. Guvf punyyratr vf vaqvivqhny, jvgu n svany cevmr sbe"
// "bar fghqrag. Fgnss zrzoref znl cnegvpvcngr ohg ner abg ryvtvoyr sbe n"
// "cevmr. Ner lbh nzbat gur irel svefg gb fbyir n pvepyr? Fraq gur uvagf"
// "jvgu rkcynangvbaf gb by@42.se gb or nqqrq gb gur yrnqreobneq. Gur"
// "uvag sbe guvf svefg cebwrpg, juvpu znl pbagnva nantenzzrq jbeqf, vf:"
// "Jbys bs ntragvir cnegvpyrf gung qvfcebir terral gb lbhe ubzrf qan"
// "gung cebjfr lbhe fgbby"

// What a shitty algorithm is this?
char	*rot13_decode(char	*encoded)
{
	size_t	alloc_sz;
	size_t	iter;
	char	*ret;

	if (!encoded)
		return (NULL);
	alloc_sz = ft_strlen(encoded);
	ret = (char *) malloc(sizeof(char) * (alloc_sz + 1));
	if (!ret)
		return (NULL);
	iter = 0;
	while (iter < alloc_sz)
	{
		if (*(encoded + iter) >= 'A' && *(encoded + iter) <= 'Z')
			ret[iter] = ((*(encoded + iter) - 'A' + 13) % 26) + 'A';
		else if (*(encoded + iter) >= 'a' && *(encoded + iter) <= 'z')
			ret[iter] = ((*(encoded + iter) - 'a' + 13) % 26) + 'a';
		else
			ret[iter] = *(encoded + iter);
		iter++;
	}
	*(ret + iter) = 0;
	return (ret);
}
