package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	words []string
	order string
	ans   bool
}{

	{
		[]string{"skuxofhyqffmvem", "pivlrvyixuwkteq", "alsgqypugsbbobl", "aaeognfoaxhcfii", "mpyonsmytxdnysa", "midsibtcmyeshoy", "ozqieboykydhjlz", "bolwcxirutfkovw", "kmbgtngnzhldnql", "xrxbriikmpxrprn", "xasnbmzcyncynqf", "srvryjpvrkjfwum", "kxcytrfssxrrksl", "foiaripeubtyyox", "yyhnjykzexgksob", "tykvetxwxbnaghl", "pkfmfhnboutbzry", "mlxxxcpeapjhwvx", "jmtcevkbcurjqhp", "hpowpmxkjiufoyz", "trbrldyxjbthcwi", "elkqzwcdljzzilp", "xuututciwchdtgp", "dznknlxbhjqlnfp", "usvebdafpehvhnn", "vgztrhsazakvkoy", "ppeowsoiwauodrd", "rwfnkmwpowiilmn", "gnptotnrcujhobx", "rfesptvhuiwtzuv", "nncoygoxusmskdj", "zrdmgclmxuygrfa", "ccuprnhgisbhnlo", "iwwnyuooaxciddu", "kyyzpnkywltfyqf", "fwvfdgyhgwnedww", "inleqhipjuvaipy", "ggwajwbrmbsvzto", "smfnzvhxnzlttqq", "hgolraueyiveyff", "bcitwifwgcvnfiz", "tporichlcybalot", "axjnikarmsedfkf", "takwnduamciroyg", "jtoikpsttsdiusp", "tlwzeycxdkigmia", "gvktgerybyghsoi", "gexklhkdamzxsar", "eaescmsyvbfhjki", "izkzehqhdpfkcfd", "riygtdcgibpigjr", "hxnngtftblikoan", "hqeyivtoimdmcgw", "srgbehdjwgvkwfd", "syrqpdzhbwrohvw", "ulghcdyoaaimdsk", "yotgykrwulptddt", "vmujiultrruvicw", "bvgazhtfaxopncl", "tlygnypwvdpqruq", "gwghjruwprmaywb", "tmjlyehemrjllsf", "jbtollpqxhcxipc", "urryhtrjdcyyxgk", "fovuiicvzbvopje", "iocnnebdisktpto", "dizpowvljuxcuyp", "lmbryijbblvbfew", "hsbdhkhaqjsyezo", "xuzrakcohgkzvja", "rqytcuxmbexynso", "muvxuufnbdxpgqp", "kazzhqfnoerazdp", "ydcbxbysbzqavgq", "uvswbtjojzodhxx", "ogficmoxohwmacf", "rsxarauxrlsugzl", "ivxddltcdfqnsku", "flxhjxcbldrhmtg", "gwcgyybialciiaz", "euizzqwnnefihcz", "ttlzrgnwhgzkirj", "geomyyrdrhkimzv", "wfoxpjisclyoygt", "iunuvuqdkeqqacf", "vfftvmtoaanoafp", "ogzwqioazjyedjq", "iltzlygzsreqlkw", "paighhiwamnafai", "aslchefeszbmokl", "opvtsdbqxgppvmj", "kfjaofmhvgfjxja", "xiwykodfpgizgky", "qsznrasrvabazev", "qpevsngotolecsi"},
		"fhgbavxiyjpueqkodmtzncslwr",
		false,
	},

	{
		[]string{"hello", "leetcode"},
		"hlabcdefgijkmnopqrstuvwxyz",
		true,
	},

	{
		[]string{"word", "world", "row"},
		"worldabcefghijkmnpqstuvxyz",
		false,
	},

	{
		[]string{"apple", "app"},
		"abcdefghijklmnopqrstuvwxyz",
		false,
	},
}

func Test_isAlienSorted(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 953. Verifying an Alien Dictionary------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: words = %v, order = %v\n【Output】: %v\n", tc.words, tc.order, isAlienSorted(tc.words, tc.order))
		ast.Equal(tc.ans, isAlienSorted(tc.words, tc.order), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_isAlienSorted(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			isAlienSorted(tc.words, tc.order)
		}
	}
}
