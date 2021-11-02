#pragma once
//#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class SVM {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        float kernels[243] = { 0 };
                        float decisions[6] = { 0 };
                        int votes[4] = { 0 };
                        kernels[0] = compute_kernel(x,   0.330149573794  , 0.023216598705 );
                        kernels[1] = compute_kernel(x,   0.683695583967  , -0.129488210435 );
                        kernels[2] = compute_kernel(x,   0.408085170458  , 0.306621467409 );
                        kernels[3] = compute_kernel(x,   0.534161823904  , 0.053451170143 );
                        kernels[4] = compute_kernel(x,   0.695518412711  , -0.147807203982 );
                        kernels[5] = compute_kernel(x,   0.686369646377  , -0.133390158181 );
                        kernels[6] = compute_kernel(x,   0.249595324663  , -0.083870612821 );
                        kernels[7] = compute_kernel(x,   0.700017098076  , -0.139410355089 );
                        kernels[8] = compute_kernel(x,   0.290820957027  , -0.189524990513 );
                        kernels[9] = compute_kernel(x,   0.744756689767  , -0.106822910254 );
                        kernels[10] = compute_kernel(x,   0.800546984054  , -0.131487563101 );
                        kernels[11] = compute_kernel(x,   0.614328615968  , -0.000443658602 );
                        kernels[12] = compute_kernel(x,   0.45654146944  , 0.055207492372 );
                        kernels[13] = compute_kernel(x,   0.421719964684  , -0.383997448318 );
                        kernels[14] = compute_kernel(x,   0.082739261923  , -0.023088991382 );
                        kernels[15] = compute_kernel(x,   0.118969067537  , 0.10313496569 );
                        kernels[16] = compute_kernel(x,   0.392962929501  , -0.104972665887 );
                        kernels[17] = compute_kernel(x,   0.634158284854  , -0.033654250137 );
                        kernels[18] = compute_kernel(x,   0.370497936094  , -0.194707284316 );
                        kernels[19] = compute_kernel(x,   0.624004390768  , -0.039590804628 );
                        kernels[20] = compute_kernel(x,   0.182405470012  , -0.037787600388 );
                        kernels[21] = compute_kernel(x,   0.718181944667  , -0.163903554555 );
                        kernels[22] = compute_kernel(x,   0.72296012053  , -0.084256442446 );
                        kernels[23] = compute_kernel(x,   0.644868262992  , -0.084763222093 );
                        kernels[24] = compute_kernel(x,   0.503223539649  , -0.03269985677 );
                        kernels[25] = compute_kernel(x,   0.205608021992  , -0.013919855387 );
                        kernels[26] = compute_kernel(x,   0.488334568095  , -0.001502975693 );
                        kernels[27] = compute_kernel(x,   0.264325258877  , -0.206037385536 );
                        kernels[28] = compute_kernel(x,   0.252679805894  , 0.065167390133 );
                        kernels[29] = compute_kernel(x,   0.354540207344  , -0.445742393312 );
                        kernels[30] = compute_kernel(x,   0.578961509491  , 0.053767388668 );
                        kernels[31] = compute_kernel(x,   0.700581170058  , -0.087752830796 );
                        kernels[32] = compute_kernel(x,   0.588156300886  , 0.31741139219 );
                        kernels[33] = compute_kernel(x,   0.50969065088  , -0.055068124695 );
                        kernels[34] = compute_kernel(x,   0.11810322384  , -0.001460537199 );
                        kernels[35] = compute_kernel(x,   0.734920006992  , -0.103817499674 );
                        kernels[36] = compute_kernel(x,   0.746713385766  , -0.111253796748 );
                        kernels[37] = compute_kernel(x,   0.545554558491  , 0.055521724162 );
                        kernels[38] = compute_kernel(x,   0.224313101814  , 0.167927564372 );
                        kernels[39] = compute_kernel(x,   0.748670506183  , -0.114228142102 );
                        kernels[40] = compute_kernel(x,   0.686388339933  , -0.126923894964 );
                        kernels[41] = compute_kernel(x,   0.784141846099  , -0.117447662685 );
                        kernels[42] = compute_kernel(x,   0.723932980216  , -0.164573545145 );
                        kernels[43] = compute_kernel(x,   0.760677072963  , -0.102745568497 );
                        kernels[44] = compute_kernel(x,   0.755340431618  , -0.097047427534 );
                        kernels[45] = compute_kernel(x,   0.526899369119  , 0.316051627359 );
                        kernels[46] = compute_kernel(x,   0.146015989463  , -0.012520366048 );
                        kernels[47] = compute_kernel(x,   0.260676595581  , -0.224749823946 );
                        kernels[48] = compute_kernel(x,   0.384042905557  , -0.007914332326 );
                        kernels[49] = compute_kernel(x,   0.735592402016  , -0.168639762959 );
                        kernels[50] = compute_kernel(x,   0.639401218904  , 0.268059026695 );
                        kernels[51] = compute_kernel(x,   0.332714447621  , -0.063016118313 );
                        kernels[52] = compute_kernel(x,   0.551710227575  , -0.05976012647 );
                        kernels[53] = compute_kernel(x,   0.691313340342  , -0.12550206562 );
                        kernels[54] = compute_kernel(x,   0.123634848721  , 0.004200104529 );
                        kernels[55] = compute_kernel(x,   0.738069118143  , -0.105996354298 );
                        kernels[56] = compute_kernel(x,   0.703531021917  , -0.094011506381 );
                        kernels[57] = compute_kernel(x,   0.611883798909  , -0.002432441609 );
                        kernels[58] = compute_kernel(x,   0.321031421855  , 0.032096737802 );
                        kernels[59] = compute_kernel(x,   0.500690715846  , 0.006464023292 );
                        kernels[60] = compute_kernel(x,   0.47811983086  , -0.01506672279 );
                        kernels[61] = compute_kernel(x,   0.430832025789  , 0.298433435701 );
                        kernels[62] = compute_kernel(x,   0.169543194591  , -0.01279293672 );
                        kernels[63] = compute_kernel(x,   0.724987844867  , -0.112622498004 );
                        kernels[64] = compute_kernel(x,   0.737804977091  , -0.170662052217 );
                        kernels[65] = compute_kernel(x,   0.617851722264  , 0.270430352025 );
                        kernels[66] = compute_kernel(x,   0.559072963626  , -0.044641295005 );
                        kernels[67] = compute_kernel(x,   0.65279054729  , -0.167918121263 );
                        kernels[68] = compute_kernel(x,   -0.182775047724  , 0.246493248883 );
                        kernels[69] = compute_kernel(x,   -0.221811927779  , 0.18856841923 );
                        kernels[70] = compute_kernel(x,   -0.058939944697  , 0.248198260126 );
                        kernels[71] = compute_kernel(x,   -0.292429746585  , 0.075777853245 );
                        kernels[72] = compute_kernel(x,   -0.186577969554  , 0.171244923714 );
                        kernels[73] = compute_kernel(x,   -0.469339468554  , -0.032193612808 );
                        kernels[74] = compute_kernel(x,   0.011844179221  , 0.29512502472 );
                        kernels[75] = compute_kernel(x,   -0.22101455474  , 0.15545961714 );
                        kernels[76] = compute_kernel(x,   -0.273669564268  , 0.279211712199 );
                        kernels[77] = compute_kernel(x,   -0.373789552388  , 0.154871609921 );
                        kernels[78] = compute_kernel(x,   -0.405444425771  , 0.041044732711 );
                        kernels[79] = compute_kernel(x,   -0.379122054198  , 0.125781161235 );
                        kernels[80] = compute_kernel(x,   -0.257348209592  , 0.162963977959 );
                        kernels[81] = compute_kernel(x,   -0.252628765151  , 0.30475559819 );
                        kernels[82] = compute_kernel(x,   -0.369997233657  , 0.143144242717 );
                        kernels[83] = compute_kernel(x,   -0.341233922312  , 0.006698312261 );
                        kernels[84] = compute_kernel(x,   -0.293163118052  , 0.236140051094 );
                        kernels[85] = compute_kernel(x,   -0.381720549989  , 0.142860032419 );
                        kernels[86] = compute_kernel(x,   -0.332332654333  , 0.061781805164 );
                        kernels[87] = compute_kernel(x,   -0.398507824728  , 0.012680694612 );
                        kernels[88] = compute_kernel(x,   -0.250600226795  , 0.161078682411 );
                        kernels[89] = compute_kernel(x,   -0.050208667764  , 0.309997345481 );
                        kernels[90] = compute_kernel(x,   -0.367534751247  , 0.173763127092 );
                        kernels[91] = compute_kernel(x,   -0.286540042384  , 0.257982256863 );
                        kernels[92] = compute_kernel(x,   -0.18190680824  , 0.232383790822 );
                        kernels[93] = compute_kernel(x,   -0.024740186969  , 0.243268360505 );
                        kernels[94] = compute_kernel(x,   -0.416221573921  , -0.012695182624 );
                        kernels[95] = compute_kernel(x,   -0.3368874857  , 0.061917501212 );
                        kernels[96] = compute_kernel(x,   -0.041523305471  , 0.274197907619 );
                        kernels[97] = compute_kernel(x,   -0.240936870597  , 0.226297305331 );
                        kernels[98] = compute_kernel(x,   -0.321376999112  , 0.00140523077 );
                        kernels[99] = compute_kernel(x,   -0.282755103183  , 0.273387993946 );
                        kernels[100] = compute_kernel(x,   -0.375751752564  , 0.138405065604 );
                        kernels[101] = compute_kernel(x,   -0.348805960216  , 0.082149049746 );
                        kernels[102] = compute_kernel(x,   0.051813625267  , 0.351976756621 );
                        kernels[103] = compute_kernel(x,   -0.27642075532  , 0.164342255321 );
                        kernels[104] = compute_kernel(x,   -0.386988725292  , 0.126805944042 );
                        kernels[105] = compute_kernel(x,   -0.018985257709  , 0.359316200602 );
                        kernels[106] = compute_kernel(x,   -0.194036860296  , 0.137876068799 );
                        kernels[107] = compute_kernel(x,   -0.365959163829  , 0.002949164225 );
                        kernels[108] = compute_kernel(x,   -0.405840930423  , 0.015762994157 );
                        kernels[109] = compute_kernel(x,   -0.047778106613  , 0.255306390448 );
                        kernels[110] = compute_kernel(x,   -0.283444917167  , 0.285351680069 );
                        kernels[111] = compute_kernel(x,   -0.432486837913  , -0.019079370351 );
                        kernels[112] = compute_kernel(x,   -0.183443879988  , 0.178941223432 );
                        kernels[113] = compute_kernel(x,   -0.230282470077  , 0.197502510331 );
                        kernels[114] = compute_kernel(x,   -0.379547499903  , 0.13154469759 );
                        kernels[115] = compute_kernel(x,   -0.29877872879  , 0.074532534305 );
                        kernels[116] = compute_kernel(x,   -0.433534063537  , -0.03179030941 );
                        kernels[117] = compute_kernel(x,   -0.232455520163  , 0.20881784516 );
                        kernels[118] = compute_kernel(x,   -0.23946787124  , 0.216903290476 );
                        kernels[119] = compute_kernel(x,   -0.383632660402  , 0.129387482263 );
                        kernels[120] = compute_kernel(x,   -0.189452961672  , 0.276235437381 );
                        kernels[121] = compute_kernel(x,   -0.347491815622  , 0.04706891848 );
                        kernels[122] = compute_kernel(x,   -0.319293349695  , 0.223608791506 );
                        kernels[123] = compute_kernel(x,   -0.279388342396  , 0.140690614938 );
                        kernels[124] = compute_kernel(x,   -0.260904220718  , 0.110455023404 );
                        kernels[125] = compute_kernel(x,   -0.23335597902  , 0.153042348987 );
                        kernels[126] = compute_kernel(x,   -0.19453369476  , 0.18894883585 );
                        kernels[127] = compute_kernel(x,   -0.384361756013  , 0.129811805156 );
                        kernels[128] = compute_kernel(x,   -0.017237653328  , 0.353764402129 );
                        kernels[129] = compute_kernel(x,   -0.195521938621  , 0.274702415875 );
                        kernels[130] = compute_kernel(x,   -0.23143438038  , 0.23113565372 );
                        kernels[131] = compute_kernel(x,   -0.195367238093  , 0.197893523211 );
                        kernels[132] = compute_kernel(x,   -0.00876711103  , 0.344830311027 );
                        kernels[133] = compute_kernel(x,   -0.220153694785  , 0.168483263366 );
                        kernels[134] = compute_kernel(x,   -0.38148445016  , 0.021054088912 );
                        kernels[135] = compute_kernel(x,   -0.189959079325  , 0.167166388413 );
                        kernels[136] = compute_kernel(x,   -0.331769598848  , 0.022352235216 );
                        kernels[137] = compute_kernel(x,   -0.379422275496  , 0.139029682991 );
                        kernels[138] = compute_kernel(x,   -0.283837938461  , 0.265479109217 );
                        kernels[139] = compute_kernel(x,   -0.190362908756  , 0.155839186631 );
                        kernels[140] = compute_kernel(x,   -0.34269554214  , -0.011040777171 );
                        kernels[141] = compute_kernel(x,   -0.287469497045  , 0.246430603115 );
                        kernels[142] = compute_kernel(x,   -0.314266997679  , 0.090934876772 );
                        kernels[143] = compute_kernel(x,   -0.201178386701  , 0.184197368219 );
                        kernels[144] = compute_kernel(x,   -0.406952706754  , 0.038899384338 );
                        kernels[145] = compute_kernel(x,   -0.378367913707  , 0.126853835421 );
                        kernels[146] = compute_kernel(x,   -0.260779409125  , 0.155891448498 );
                        kernels[147] = compute_kernel(x,   -0.201435897766  , 0.227572988423 );
                        kernels[148] = compute_kernel(x,   0.00293116042  , 0.343617524244 );
                        kernels[149] = compute_kernel(x,   -0.26011829283  , 0.172726719627 );
                        kernels[150] = compute_kernel(x,   0.596395680788  , -0.07133963365 );
                        kernels[151] = compute_kernel(x,   0.489005486326  , 0.076019906374 );
                        kernels[152] = compute_kernel(x,   0.642954749887  , 0.055154249377 );
                        kernels[153] = compute_kernel(x,   0.622260658475  , 0.185301555321 );
                        kernels[154] = compute_kernel(x,   0.688697911446  , 0.164924388219 );
                        kernels[155] = compute_kernel(x,   0.394716256232  , -0.024396250778 );
                        kernels[156] = compute_kernel(x,   0.225383368885  , 0.054259844942 );
                        kernels[157] = compute_kernel(x,   0.640878225937  , 0.258379480665 );
                        kernels[158] = compute_kernel(x,   0.26846728988  , 0.104749505916 );
                        kernels[159] = compute_kernel(x,   0.440903609341  , 0.222158150088 );
                        kernels[160] = compute_kernel(x,   0.481213400261  , 0.247603446003 );
                        kernels[161] = compute_kernel(x,   0.684104044655  , 0.151706173343 );
                        kernels[162] = compute_kernel(x,   0.738826985154  , 0.203556996383 );
                        kernels[163] = compute_kernel(x,   0.659986176384  , 0.195061297189 );
                        kernels[164] = compute_kernel(x,   -0.363784546801  , -0.201291894777 );
                        kernels[165] = compute_kernel(x,   -0.360835422673  , -0.19741280684 );
                        kernels[166] = compute_kernel(x,   -0.202002718577  , -0.131785821326 );
                        kernels[167] = compute_kernel(x,   -0.228393348416  , -0.137200398761 );
                        kernels[168] = compute_kernel(x,   -0.134827010534  , 0.04441211962 );
                        kernels[169] = compute_kernel(x,   -0.339591153175  , -0.172517695707 );
                        kernels[170] = compute_kernel(x,   -0.333761499625  , -0.163287527354 );
                        kernels[171] = compute_kernel(x,   -0.328254000923  , -0.154930585825 );
                        kernels[172] = compute_kernel(x,   -0.366046968275  , -0.204509917337 );
                        kernels[173] = compute_kernel(x,   -0.329211611795  , -0.155354485153 );
                        kernels[174] = compute_kernel(x,   -0.318689497933  , -0.133288674549 );
                        kernels[175] = compute_kernel(x,   -0.227028181391  , -0.122286447605 );
                        kernels[176] = compute_kernel(x,   -0.338872865702  , -0.164396649531 );
                        kernels[177] = compute_kernel(x,   -0.09113415774  , 0.059795990078 );
                        kernels[178] = compute_kernel(x,   -0.131860538331  , 0.045708822207 );
                        kernels[179] = compute_kernel(x,   -0.374610310568  , -0.228696918843 );
                        kernels[180] = compute_kernel(x,   -0.369753344225  , -0.196836927962 );
                        kernels[181] = compute_kernel(x,   -0.371446273369  , -0.171587001398 );
                        kernels[182] = compute_kernel(x,   -0.29969715905  , -0.151369441764 );
                        kernels[183] = compute_kernel(x,   -0.13230022078  , 0.041429992413 );
                        kernels[184] = compute_kernel(x,   -0.365925172476  , -0.215612667155 );
                        kernels[185] = compute_kernel(x,   -0.201065939138  , -0.13418870435 );
                        kernels[186] = compute_kernel(x,   -0.270486315425  , -0.208708970732 );
                        kernels[187] = compute_kernel(x,   -0.367747911502  , -0.214551859922 );
                        kernels[188] = compute_kernel(x,   -0.36553557979  , -0.214327831521 );
                        kernels[189] = compute_kernel(x,   -0.366111294782  , -0.217546277647 );
                        kernels[190] = compute_kernel(x,   -0.31808873806  , -0.128573231344 );
                        kernels[191] = compute_kernel(x,   -0.32338965505  , -0.150203699231 );
                        kernels[192] = compute_kernel(x,   -0.362040371026  , -0.225431428469 );
                        kernels[193] = compute_kernel(x,   -0.288660545372  , -0.151746296843 );
                        kernels[194] = compute_kernel(x,   -0.03171219017  , 0.031653288814 );
                        kernels[195] = compute_kernel(x,   -0.375285887808  , -0.206690866571 );
                        kernels[196] = compute_kernel(x,   -0.364583874303  , -0.157441942477 );
                        kernels[197] = compute_kernel(x,   -0.110441271942  , 0.049870426182 );
                        kernels[198] = compute_kernel(x,   -0.34468401431  , -0.178092804523 );
                        kernels[199] = compute_kernel(x,   -0.371903919284  , -0.189071047386 );
                        kernels[200] = compute_kernel(x,   -0.358208453393  , -0.194406945726 );
                        kernels[201] = compute_kernel(x,   -0.189621769308  , -0.120075507602 );
                        kernels[202] = compute_kernel(x,   -0.306330725578  , -0.133453791746 );
                        kernels[203] = compute_kernel(x,   -0.378252360012  , -0.207987569158 );
                        kernels[204] = compute_kernel(x,   -0.207146697678  , -0.118191086152 );
                        kernels[205] = compute_kernel(x,   -0.356750262173  , -0.195255591512 );
                        kernels[206] = compute_kernel(x,   -0.333872487287  , -0.160730146606 );
                        kernels[207] = compute_kernel(x,   -0.326427291813  , -0.155074860672 );
                        kernels[208] = compute_kernel(x,   -0.374242334156  , -0.210321345072 );
                        kernels[209] = compute_kernel(x,   -0.383849230102  , -0.230877868078 );
                        kernels[210] = compute_kernel(x,   -0.374245762763  , -0.22890908029 );
                        kernels[211] = compute_kernel(x,   -0.209791799873  , -0.098697041425 );
                        kernels[212] = compute_kernel(x,   -0.26110765825  , -0.101802824335 );
                        kernels[213] = compute_kernel(x,   -0.137554159339  , 0.035418270185 );
                        kernels[214] = compute_kernel(x,   -0.255049489437  , -0.09172443376 );
                        kernels[215] = compute_kernel(x,   -0.358873539773  , -0.212158749241 );
                        kernels[216] = compute_kernel(x,   -0.377937901969  , -0.211193724765 );
                        kernels[217] = compute_kernel(x,   -0.227914944981  , -0.150348374797 );
                        kernels[218] = compute_kernel(x,   -0.378898624172  , -0.198992872595 );
                        kernels[219] = compute_kernel(x,   -0.242183482096  , -0.109725666873 );
                        kernels[220] = compute_kernel(x,   -0.377187190085  , -0.228708785797 );
                        kernels[221] = compute_kernel(x,   -0.355882022689  , -0.209365049573 );
                        kernels[222] = compute_kernel(x,   -0.261887120114  , -0.191570341215 );
                        kernels[223] = compute_kernel(x,   -0.310308009747  , -0.125543636323 );
                        kernels[224] = compute_kernel(x,   -0.378666997579  , -0.210769401872 );
                        kernels[225] = compute_kernel(x,   -0.3113515634  , -0.121913157822 );
                        kernels[226] = compute_kernel(x,   -0.215995220522  , -0.092367348352 );
                        kernels[227] = compute_kernel(x,   -0.358379480201  , -0.172756906183 );
                        kernels[228] = compute_kernel(x,   -0.361642446981  , -0.15764223697 );
                        kernels[229] = compute_kernel(x,   -0.309064097044  , -0.117198138182 );
                        kernels[230] = compute_kernel(x,   -0.352275508987  , -0.191813540552 );
                        kernels[231] = compute_kernel(x,   -0.375285887808  , -0.206690866571 );
                        kernels[232] = compute_kernel(x,   -0.184825720027  , -0.129301513703 );
                        kernels[233] = compute_kernel(x,   -0.374921340003  , -0.206903028018 );
                        kernels[234] = compute_kernel(x,   -0.347775710919  , -0.186874492511 );
                        kernels[235] = compute_kernel(x,   -0.311741156086  , -0.123197993456 );
                        kernels[236] = compute_kernel(x,   -0.209719735774  , -0.137566657581 );
                        kernels[237] = compute_kernel(x,   -0.165340667052  , -0.117029086429 );
                        kernels[238] = compute_kernel(x,   -0.239298142998  , -0.136554142078 );
                        kernels[239] = compute_kernel(x,   -0.333911768912  , -0.172269509835 );
                        kernels[240] = compute_kernel(x,   -0.368259299987  , -0.204733945737 );
                        kernels[241] = compute_kernel(x,   -0.295108306871  , -0.163109523051 );
                        kernels[242] = compute_kernel(x,   -0.35859804608  , -0.195691781359 );
                        decisions[0] = -0.999999999056
                        + kernels[0]
                        + kernels[1]
                        + kernels[2]
                        + kernels[3]
                        + kernels[4]
                        + kernels[5]
                        + kernels[6]
                        + kernels[7]
                        + kernels[8]
                        + kernels[9]
                        + kernels[10]
                        + kernels[11]
                        + kernels[12]
                        + kernels[13]
                        + kernels[14]
                        + kernels[15]
                        + kernels[16]
                        + kernels[17]
                        + kernels[18]
                        + kernels[19]
                        + kernels[20]
                        + kernels[21]
                        + kernels[22]
                        + kernels[23]
                        + kernels[24]
                        + kernels[25]
                        + kernels[26]
                        + kernels[27]
                        + kernels[28]
                        + kernels[29]
                        + kernels[30]
                        + kernels[31]
                        + kernels[32]
                        + kernels[33]
                        + kernels[34]
                        + kernels[35]
                        + kernels[36]
                        + kernels[37]
                        + kernels[38]
                        + kernels[39]
                        + kernels[40]
                        + kernels[41]
                        + kernels[42]
                        + kernels[43]
                        + kernels[44]
                        + kernels[45]
                        + kernels[46]
                        + kernels[47]
                        + kernels[48]
                        + kernels[49]
                        + kernels[50]
                        + kernels[51]
                        + kernels[52]
                        + kernels[53]
                        + kernels[54]
                        + kernels[55]
                        + kernels[56]
                        + kernels[57]
                        + kernels[58]
                        + kernels[59]
                        + kernels[60]
                        + kernels[61]
                        + kernels[62]
                        + kernels[63]
                        + kernels[64]
                        + kernels[65]
                        + kernels[66]
                        + kernels[67]
                        - kernels[68]
                        - kernels[69]
                        - kernels[70]
                        - kernels[71]
                        - kernels[72]
                        - kernels[74]
                        - kernels[75]
                        - kernels[76]
                        - kernels[79]
                        - kernels[80]
                        - kernels[81]
                        - kernels[82]
                        - kernels[83]
                        - kernels[84]
                        - kernels[86]
                        - kernels[87]
                        - kernels[88]
                        - kernels[89]
                        - kernels[90]
                        - kernels[91]
                        - kernels[92]
                        - kernels[93]
                        - kernels[95]
                        - kernels[96]
                        - kernels[97]
                        - kernels[98]
                        - kernels[99]
                        - kernels[100]
                        - kernels[101]
                        - kernels[102]
                        - kernels[103]
                        - kernels[105]
                        - kernels[106]
                        - kernels[107]
                        - kernels[109]
                        - kernels[110]
                        - kernels[112]
                        - kernels[113]
                        - kernels[115]
                        - kernels[117]
                        - kernels[118]
                        - kernels[120]
                        - kernels[121]
                        - kernels[122]
                        - kernels[123]
                        - kernels[124]
                        - kernels[125]
                        - kernels[126]
                        - kernels[128]
                        - kernels[129]
                        - kernels[130]
                        - kernels[131]
                        - kernels[132]
                        - kernels[133]
                        - kernels[134]
                        - kernels[135]
                        - kernels[136]
                        - kernels[138]
                        - kernels[139]
                        - kernels[140]
                        - kernels[141]
                        - kernels[142]
                        - kernels[143]
                        - kernels[145]
                        - kernels[146]
                        - kernels[147]
                        - kernels[148]
                        - kernels[149]
                        ;
                        decisions[1] = 0.999999999991
                        + kernels[2]
                        + kernels[10]
                        + kernels[14]
                        + kernels[30]
                        + kernels[32]
                        + kernels[34]
                        + kernels[37]
                        + kernels[41]
                        + kernels[45]
                        + kernels[50]
                        + kernels[54]
                        + kernels[61]
                        + kernels[65]
                        + kernels[67]
                        - kernels[150]
                        - kernels[151]
                        - kernels[152]
                        - kernels[153]
                        - kernels[154]
                        - kernels[155]
                        - kernels[156]
                        - kernels[157]
                        - kernels[158]
                        - kernels[159]
                        - kernels[160]
                        - kernels[161]
                        - kernels[162]
                        - kernels[163]
                        ;
                        decisions[2] = -0.999999999143
                        + kernels[0]
                        + kernels[1]
                        + kernels[2]
                        + kernels[3]
                        + kernels[4]
                        + kernels[5]
                        + kernels[6]
                        + kernels[7]
                        + kernels[8]
                        + kernels[9]
                        + kernels[10]
                        + kernels[11]
                        + kernels[12]
                        + kernels[13]
                        + kernels[14]
                        + kernels[15]
                        + kernels[16]
                        + kernels[17]
                        + kernels[18]
                        + kernels[19]
                        + kernels[20]
                        + kernels[21]
                        + kernels[22]
                        + kernels[23]
                        + kernels[24]
                        + kernels[25]
                        + kernels[26]
                        + kernels[27]
                        + kernels[28]
                        + kernels[29]
                        + kernels[30]
                        + kernels[31]
                        + kernels[32]
                        + kernels[33]
                        + kernels[34]
                        + kernels[35]
                        + kernels[36]
                        + kernels[37]
                        + kernels[38]
                        + kernels[39]
                        + kernels[40]
                        + kernels[41]
                        + kernels[42]
                        + kernels[43]
                        + kernels[44]
                        + kernels[45]
                        + kernels[46]
                        + kernels[47]
                        + kernels[48]
                        + kernels[49]
                        + kernels[50]
                        + kernels[51]
                        + kernels[52]
                        + kernels[53]
                        + kernels[54]
                        + kernels[55]
                        + kernels[56]
                        + kernels[57]
                        + kernels[58]
                        + kernels[59]
                        + kernels[60]
                        + kernels[61]
                        + kernels[62]
                        + kernels[63]
                        + kernels[64]
                        + kernels[65]
                        + kernels[66]
                        + kernels[67]
                        - kernels[164]
                        - kernels[165]
                        - kernels[166]
                        - kernels[167]
                        - kernels[168]
                        - kernels[169]
                        - kernels[170]
                        - kernels[171]
                        - kernels[172]
                        - kernels[173]
                        - kernels[174]
                        - kernels[175]
                        - kernels[176]
                        - kernels[177]
                        - kernels[178]
                        - kernels[180]
                        - kernels[181]
                        - kernels[182]
                        - kernels[183]
                        - kernels[184]
                        - kernels[185]
                        - kernels[186]
                        - kernels[187]
                        - kernels[188]
                        - kernels[189]
                        - kernels[190]
                        - kernels[191]
                        - kernels[192]
                        - kernels[193]
                        - kernels[194]
                        - kernels[196]
                        - kernels[197]
                        - kernels[198]
                        - kernels[199]
                        - kernels[200]
                        - kernels[201]
                        - kernels[202]
                        - kernels[204]
                        - kernels[205]
                        - kernels[206]
                        - kernels[207]
                        - kernels[210]
                        - kernels[211]
                        - kernels[212]
                        - kernels[213]
                        - kernels[214]
                        - kernels[215]
                        - kernels[217]
                        - kernels[219]
                        - kernels[221]
                        - kernels[222]
                        - kernels[223]
                        - kernels[225]
                        - kernels[226]
                        - kernels[227]
                        - kernels[228]
                        - kernels[229]
                        - kernels[230]
                        - kernels[232]
                        - kernels[234]
                        - kernels[235]
                        - kernels[236]
                        - kernels[237]
                        - kernels[238]
                        - kernels[239]
                        - kernels[240]
                        - kernels[241]
                        - kernels[242]
                        ;
                        decisions[3] = 0.999999999977
                        + kernels[70]
                        + kernels[72]
                        + kernels[74]
                        + kernels[89]
                        + kernels[93]
                        + kernels[96]
                        + kernels[102]
                        + kernels[106]
                        + kernels[109]
                        + kernels[112]
                        + kernels[128]
                        + kernels[132]
                        + kernels[148]
                        + kernels[149]
                        - kernels[150]
                        - kernels[151]
                        - kernels[152]
                        - kernels[153]
                        - kernels[154]
                        - kernels[155]
                        - kernels[156]
                        - kernels[157]
                        - kernels[158]
                        - kernels[159]
                        - kernels[160]
                        - kernels[161]
                        - kernels[162]
                        - kernels[163]
                        ;
                        decisions[4] = 0.999999999873
                        + kernels[68]
                        + kernels[69]
                        + kernels[70]
                        + kernels[71]
                        + kernels[72]
                        + kernels[73]
                        + kernels[74]
                        + kernels[75]
                        + kernels[76]
                        + kernels[77]
                        + kernels[78]
                        + kernels[79]
                        + kernels[80]
                        + kernels[81]
                        + kernels[82]
                        + kernels[83]
                        + kernels[84]
                        + kernels[85]
                        + kernels[86]
                        + kernels[87]
                        + kernels[88]
                        + kernels[89]
                        + kernels[90]
                        + kernels[91]
                        + kernels[92]
                        + kernels[93]
                        + kernels[94]
                        + kernels[95]
                        + kernels[96]
                        + kernels[97]
                        + kernels[98]
                        + kernels[100]
                        + kernels[101]
                        + kernels[102]
                        + kernels[103]
                        + kernels[104]
                        + kernels[105]
                        + kernels[106]
                        + kernels[107]
                        + kernels[108]
                        + kernels[109]
                        + kernels[111]
                        + kernels[112]
                        + kernels[113]
                        + kernels[114]
                        + kernels[115]
                        + kernels[116]
                        + kernels[117]
                        + kernels[118]
                        + kernels[119]
                        + kernels[120]
                        + kernels[121]
                        + kernels[123]
                        + kernels[124]
                        + kernels[125]
                        + kernels[126]
                        + kernels[127]
                        + kernels[128]
                        + kernels[129]
                        + kernels[130]
                        + kernels[131]
                        + kernels[132]
                        + kernels[133]
                        + kernels[134]
                        + kernels[135]
                        + kernels[136]
                        + kernels[137]
                        + kernels[138]
                        + kernels[139]
                        + kernels[140]
                        + kernels[141]
                        + kernels[142]
                        + kernels[143]
                        + kernels[144]
                        + kernels[145]
                        + kernels[146]
                        + kernels[147]
                        + kernels[148]
                        + kernels[149]
                        - kernels[164]
                        - kernels[165]
                        - kernels[166]
                        - kernels[167]
                        - kernels[168]
                        - kernels[169]
                        - kernels[170]
                        - kernels[171]
                        - kernels[172]
                        - kernels[173]
                        - kernels[174]
                        - kernels[175]
                        - kernels[176]
                        - kernels[177]
                        - kernels[178]
                        - kernels[179]
                        - kernels[180]
                        - kernels[181]
                        - kernels[182]
                        - kernels[183]
                        - kernels[184]
                        - kernels[185]
                        - kernels[186]
                        - kernels[187]
                        - kernels[188]
                        - kernels[189]
                        - kernels[190]
                        - kernels[191]
                        - kernels[192]
                        - kernels[193]
                        - kernels[194]
                        - kernels[195]
                        - kernels[196]
                        - kernels[197]
                        - kernels[198]
                        - kernels[199]
                        - kernels[200]
                        - kernels[201]
                        - kernels[202]
                        - kernels[203]
                        - kernels[204]
                        - kernels[205]
                        - kernels[206]
                        - kernels[207]
                        - kernels[208]
                        - kernels[209]
                        - kernels[210]
                        - kernels[211]
                        - kernels[212]
                        - kernels[213]
                        - kernels[214]
                        - kernels[215]
                        - kernels[216]
                        - kernels[217]
                        - kernels[218]
                        - kernels[219]
                        - kernels[220]
                        - kernels[221]
                        - kernels[222]
                        - kernels[223]
                        - kernels[224]
                        - kernels[225]
                        - kernels[226]
                        - kernels[227]
                        - kernels[228]
                        - kernels[229]
                        - kernels[230]
                        - kernels[231]
                        - kernels[232]
                        - kernels[233]
                        - kernels[234]
                        - kernels[235]
                        - kernels[236]
                        - kernels[237]
                        - kernels[238]
                        - kernels[239]
                        - kernels[240]
                        - kernels[241]
                        - kernels[242]
                        ;
                        decisions[5] = -0.999999999962
                        + kernels[150]
                        + kernels[151]
                        + kernels[152]
                        + kernels[153]
                        + kernels[154]
                        + kernels[155]
                        + kernels[156]
                        + kernels[157]
                        + kernels[158]
                        + kernels[159]
                        + kernels[160]
                        + kernels[161]
                        + kernels[162]
                        + kernels[163]
                        - kernels[166]
                        - kernels[168]
                        - kernels[177]
                        - kernels[178]
                        - kernels[183]
                        - kernels[185]
                        - kernels[194]
                        - kernels[197]
                        - kernels[201]
                        - kernels[204]
                        - kernels[211]
                        - kernels[213]
                        - kernels[232]
                        - kernels[237]
                        ;
                        votes[decisions[0] > 0 ? 0 : 1] += 1;
                        votes[decisions[1] > 0 ? 0 : 2] += 1;
                        votes[decisions[2] > 0 ? 0 : 3] += 1;
                        votes[decisions[3] > 0 ? 1 : 2] += 1;
                        votes[decisions[4] > 0 ? 1 : 3] += 1;
                        votes[decisions[5] > 0 ? 2 : 3] += 1;
                        int val = votes[0];
                        int idx = 0;

                        for (int i = 1; i < 4; i++) {
                            if (votes[i] > val) {
                                val = votes[i];
                                idx = i;
                            }
                        }

                        return idx;
                    }

                protected:
                    /**
                    * Compute kernel between feature vector and support vector.
                    * Kernel type: poly
                    */
                    float compute_kernel(float *x, ...) {
                        va_list w;
                        va_start(w, 2);
                        float kernel = 0.0;

                        for (uint16_t i = 0; i < 2; i++) {
                            kernel += x[i] * va_arg(w, double);
                        }

                        return pow((0.001 * kernel) + 0.0, 3);
                    }
                };
            }
        }
    }
