/*
 *  Atpdec
 *  Copyright (c) 2003 by Thierry Leconte (F4DWV)
 *
 *      $Id$
 *
 *   This library is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Library General Public License for more details.
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */
#define IQFilterLen 151
float Icoeff[151] = {
 2.2325742843e-04, 2.2570278515e-04, 5.4944198549e-04,-8.6744539657e-05,
 6.1428159970e-04,-4.9687907348e-05, 2.3702354115e-04, 3.0264117527e-04,
-3.4665776348e-04, 5.2848074680e-04,-6.1753398110e-04, 1.3993608700e-04,
-3.0008159593e-04,-8.1154328485e-04, 1.8022679170e-04,-1.5720199503e-03,
-3.8239337999e-05,-1.3741462473e-03,-1.2726627383e-03,-4.3328174632e-04,
-2.6172382938e-03,-1.7823982243e-05,-2.6269784384e-03,-1.1136815612e-03,
-9.8450124073e-04,-2.9497818647e-03, 7.2619879788e-04,-3.3279082742e-03,
 4.9552201209e-04,-9.6400601705e-04,-1.5807647070e-03, 2.5724898362e-03,
-2.7159757697e-03, 3.9918684723e-03,-1.8644952761e-04, 1.9635192361e-03,
 5.1208745535e-03,-6.5636214538e-04, 8.6991026256e-03, 6.6682087199e-04,
 6.9770091456e-03, 6.7610342755e-03, 1.9312583597e-03, 1.2516505728e-02,
-4.0937464744e-05, 1.1476038446e-02, 4.9038325820e-03, 3.3291562530e-03,
 1.2404842225e-02,-4.2288653974e-03, 1.2935433081e-02,-3.0148097682e-03,
 2.0521344454e-03, 5.5762144444e-03,-1.2818561474e-02, 9.6027727293e-03,
-1.8205698550e-02,-1.7280919557e-03,-9.3032131482e-03,-2.4414363128e-02,
 1.6839166970e-03,-3.9797698737e-02,-4.8196639244e-03,-3.2146070180e-02,
-3.4343377421e-02,-8.3583656070e-03,-6.6171220524e-02, 1.5264230826e-03,
-6.6097291361e-02,-3.1651889619e-02,-1.6711859701e-02,-1.0684451613e-01,
 6.1593047818e-02,-1.8604836192e-01, 1.2071892074e-01, 7.7996698006e-01,
 1.2071892074e-01,-1.8604836192e-01, 6.1593047818e-02,-1.0684451613e-01,
-1.6711859701e-02,-3.1651889619e-02,-6.6097291361e-02, 1.5264230826e-03,
-6.6171220524e-02,-8.3583656070e-03,-3.4343377421e-02,-3.2146070180e-02,
-4.8196639244e-03,-3.9797698737e-02, 1.6839166970e-03,-2.4414363128e-02,
-9.3032131482e-03,-1.7280919557e-03,-1.8205698550e-02, 9.6027727293e-03,
-1.2818561474e-02, 5.5762144444e-03, 2.0521344454e-03,-3.0148097682e-03,
 1.2935433081e-02,-4.2288653974e-03, 1.2404842225e-02, 3.3291562530e-03,
 4.9038325820e-03, 1.1476038446e-02,-4.0937464744e-05, 1.2516505728e-02,
 1.9312583597e-03, 6.7610342755e-03, 6.9770091456e-03, 6.6682087199e-04,
 8.6991026256e-03,-6.5636214538e-04, 5.1208745535e-03, 1.9635192361e-03,
-1.8644952761e-04, 3.9918684723e-03,-2.7159757697e-03, 2.5724898362e-03,
-1.5807647070e-03,-9.6400601705e-04, 4.9552201209e-04,-3.3279082742e-03,
 7.2619879788e-04,-2.9497818647e-03,-9.8450124073e-04,-1.1136815612e-03,
-2.6269784384e-03,-1.7823982243e-05,-2.6172382938e-03,-4.3328174632e-04,
-1.2726627383e-03,-1.3741462473e-03,-3.8239337999e-05,-1.5720199503e-03,
 1.8022679170e-04,-8.1154328485e-04,-3.0008159593e-04, 1.3993608700e-04,
-6.1753398110e-04, 5.2848074680e-04,-3.4665776348e-04, 3.0264117527e-04,
 2.3702354115e-04,-4.9687907348e-05, 6.1428159970e-04,-8.6744539657e-05,
 5.4944198549e-04, 2.2570278515e-04, 2.2325742843e-04
};

float Qcoeff[151] = {
-4.2794269223e-04, 1.8397163024e-04,-4.4785330284e-04,-1.6627304228e-04,
-1.7519563571e-04,-6.6303904496e-04, 3.0560801452e-05,-8.7995185699e-04,
-2.0511283957e-04,-5.8191603551e-04,-8.4615386905e-04,-6.3742453554e-05,
-1.3147433754e-03, 1.7346439781e-05,-9.8119119480e-04,-6.3644034234e-04,
 5.7395024970e-05,-1.3889089625e-03, 8.2841163975e-04,-1.1039838850e-03,
 4.5188354450e-04, 5.5581740182e-04,-6.2919746234e-04, 2.3772351253e-03,
-7.3475237168e-04, 2.6219466447e-03, 1.2578132143e-03, 1.1049416742e-03,
 4.1962479555e-03,-8.2609879762e-05, 5.3261208370e-03, 1.3772341565e-03,
 3.2602876090e-03, 5.0056447374e-03, 9.4749957243e-05, 7.1744053356e-03,
-3.2877105453e-04, 4.6945227130e-03, 3.0962146156e-03,-1.0999907749e-03,
 6.4737184289e-03,-4.8244158496e-03, 4.3627462751e-03,-2.7164327070e-03,
-3.8309093084e-03, 2.2349582872e-03,-1.1750018328e-02, 2.2697803009e-03,
-1.2013419762e-02,-6.6510513229e-03,-4.9179283848e-03,-1.8647664418e-02,
 8.7767339485e-05,-2.2229998741e-02,-6.1730938556e-03,-1.2584041201e-02,
-2.0928200446e-02, 9.7324325774e-04,-2.9054318745e-02, 2.6188181509e-03,
-1.7455558105e-02,-1.2275964282e-02, 8.7758192834e-03,-2.7366348536e-02,
 2.6792609619e-02,-1.6892171021e-02, 1.7352137440e-02, 2.8542292813e-02,
-9.9625636977e-03, 8.6008409146e-02,-1.0376631651e-02, 1.1271117143e-01,
 8.8298265751e-02, 7.9991566706e-02, 5.8639987374e-01,-0.0000000000e-00,
-5.8639987374e-01,-7.9991566706e-02,-8.8298265751e-02,-1.1271117143e-01,
 1.0376631651e-02,-8.6008409146e-02, 9.9625636977e-03,-2.8542292813e-02,
-1.7352137440e-02, 1.6892171021e-02,-2.6792609619e-02, 2.7366348536e-02,
-8.7758192834e-03, 1.2275964282e-02, 1.7455558105e-02,-2.6188181509e-03,
 2.9054318745e-02,-9.7324325774e-04, 2.0928200446e-02, 1.2584041201e-02,
 6.1730938556e-03, 2.2229998741e-02,-8.7767339485e-05, 1.8647664418e-02,
 4.9179283848e-03, 6.6510513229e-03, 1.2013419762e-02,-2.2697803009e-03,
 1.1750018328e-02,-2.2349582872e-03, 3.8309093084e-03, 2.7164327070e-03,
-4.3627462751e-03, 4.8244158496e-03,-6.4737184289e-03, 1.0999907749e-03,
-3.0962146156e-03,-4.6945227130e-03, 3.2877105453e-04,-7.1744053356e-03,
-9.4749957243e-05,-5.0056447374e-03,-3.2602876090e-03,-1.3772341565e-03,
-5.3261208370e-03, 8.2609879762e-05,-4.1962479555e-03,-1.1049416742e-03,
-1.2578132143e-03,-2.6219466447e-03, 7.3475237168e-04,-2.3772351253e-03,
 6.2919746234e-04,-5.5581740182e-04,-4.5188354450e-04, 1.1039838850e-03,
-8.2841163975e-04, 1.3889089625e-03,-5.7395024970e-05, 6.3644034234e-04,
 9.8119119480e-04,-1.7346439781e-05, 1.3147433754e-03, 6.3742453554e-05,
 8.4615386905e-04, 5.8191603551e-04, 2.0511283957e-04, 8.7995185699e-04,
-3.0560801452e-05, 6.6303904496e-04, 1.7519563571e-04, 1.6627304228e-04,
 4.4785330284e-04,-1.8397163024e-04, 4.2794269223e-04
};

#define SyncFilterLen 30
static float ISync[SyncFilterLen]={
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02
};
static float QSync[SyncFilterLen]={
 -3.125e-02,-3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02,-3.125e-02,3.571428e-02,3.571428e-02,
 -3.125e-02
};

#define RSFilterLen 1591
static float rsfilter[RSFilterLen] = {
 0.0,3.7950625746e-07, 7.6001859743e-07, 1.1415897914e-06,
 1.5242727912e-06, 1.9081206871e-06, 2.2931866654e-06, 2.6795239658e-06,
 3.0671858386e-06, 3.4562255014e-06, 3.8466960961e-06, 4.2386506453e-06,
 4.6321420085e-06, 5.0272228381e-06, 5.4239455359e-06, 5.8223622081e-06,
 6.2225246219e-06, 6.6244841603e-06, 7.0282917779e-06, 7.4339979562e-06,
 7.8416526592e-06, 8.2513052879e-06, 8.6630046363e-06, 9.0767988460e-06,
 9.4927353615e-06, 9.9108608857e-06, 1.0331221334e-05, 1.0753861792e-05,
 1.1178826466e-05, 1.1606158644e-05, 1.2035900647e-05, 1.2468093785e-05,
 1.2902778316e-05, 1.3339993396e-05, 1.3779777040e-05, 1.4222166074e-05,
 1.4667196094e-05, 1.5114901421e-05, 1.5565315058e-05, 1.6018468647e-05,
 1.6474392423e-05, 1.6933115176e-05, 1.7394664207e-05, 1.7859065281e-05,
 1.8326342592e-05, 1.8796518718e-05, 1.9269614578e-05, 1.9745649395e-05,
 2.0224640651e-05, 2.0706604052e-05, 2.1191553481e-05, 2.1679500965e-05,
 2.2170456632e-05, 2.2664428676e-05, 2.3161423314e-05, 2.3661444750e-05,
 2.4164495141e-05, 2.4670574556e-05, 2.5179680941e-05, 2.5691810082e-05,
 2.6206955574e-05, 2.6725108782e-05, 2.7246258806e-05, 2.7770392453e-05,
 2.8297494197e-05, 2.8827546152e-05, 2.9360528038e-05, 2.9896417149e-05,
 3.0435188325e-05, 3.0976813919e-05, 3.1521263770e-05, 3.2068505173e-05,
 3.2618502852e-05, 3.3171218934e-05, 3.3726612919e-05, 3.4284641659e-05,
 3.4845259328e-05, 3.5408417403e-05, 3.5974064636e-05, 3.6542147034e-05,
 3.7112607836e-05, 3.7685387493e-05, 3.8260423646e-05, 3.8837651110e-05,
 3.9417001850e-05, 3.9998404969e-05, 4.0581786687e-05, 4.1167070327e-05,
 4.1754176299e-05, 4.2343022087e-05, 4.2933522235e-05, 4.3525588332e-05,
 4.4119129007e-05, 4.4714049910e-05, 4.5310253710e-05, 4.5907640081e-05,
 4.6506105698e-05, 4.7105544228e-05, 4.7705846324e-05, 4.8306899622e-05,
 4.8908588735e-05, 4.9510795252e-05, 5.0113397738e-05, 5.0716271725e-05,
 5.1319289724e-05, 5.1922321217e-05, 5.2525232664e-05, 5.3127887502e-05,
 5.3730146156e-05, 5.4331866037e-05, 5.4932901556e-05, 5.5533104125e-05,
 5.6132322167e-05, 5.6730401131e-05, 5.7327183494e-05, 5.7922508779e-05,
 5.8516213569e-05, 5.9108131514e-05, 5.9698093353e-05, 6.0285926926e-05,
 6.0871457195e-05, 6.1454506256e-05, 6.2034893367e-05, 6.2612434961e-05,
 6.3186944673e-05, 6.3758233357e-05, 6.4326109118e-05, 6.4890377328e-05,
 6.5450840659e-05, 6.6007299107e-05, 6.6559550021e-05, 6.7107388130e-05,
 6.7650605579e-05, 6.8188991955e-05, 6.8722334323e-05, 6.9250417260e-05,
 6.9773022885e-05, 7.0289930903e-05, 7.0800918635e-05, 7.1305761060e-05,
 7.1804230854e-05, 7.2296098428e-05, 7.2781131971e-05, 7.3259097496e-05,
 7.3729758875e-05, 7.4192877893e-05, 7.4648214288e-05, 7.5095525799e-05,
 7.5534568215e-05, 7.5965095424e-05, 7.6386859459e-05, 7.6799610555e-05,
 7.7203097196e-05, 7.7597066172e-05, 7.7981262629e-05, 7.8355430128e-05,
 7.8719310698e-05, 7.9072644894e-05, 7.9415171857e-05, 7.9746629367e-05,
 8.0066753913e-05, 8.0375280743e-05, 8.0671943934e-05, 8.0956476450e-05,
 8.1228610209e-05, 8.1488076144e-05, 8.1734604273e-05, 8.1967923761e-05,
 8.2187762990e-05, 8.2393849628e-05, 8.2585910696e-05, 8.2763672636e-05,
 8.2926861388e-05, 8.3075202457e-05, 8.3208420983e-05, 8.3326241823e-05,
 8.3428389614e-05, 8.3514588856e-05, 8.3584563985e-05, 8.3638039448e-05,
 8.3674739779e-05, 8.3694389682e-05, 8.3696714102e-05, 8.3681438312e-05,
 8.3648287984e-05, 8.3596989278e-05, 8.3527268917e-05, 8.3438854270e-05,
 8.3331473436e-05, 8.3204855326e-05, 8.3058729744e-05, 8.2892827475e-05,
 8.2706880366e-05, 8.2500621413e-05, 8.2273784846e-05, 8.2026106214e-05,
 8.1757322474e-05, 8.1467172075e-05, 8.1155395046e-05, 8.0821733085e-05,
 8.0465929646e-05, 8.0087730028e-05, 7.9686881464e-05, 7.9263133209e-05,
 7.8816236631e-05, 7.8345945299e-05, 7.7852015075e-05, 7.7334204203e-05,
 7.6792273401e-05, 7.6225985948e-05, 7.5635107781e-05, 7.5019407579e-05,
 7.4378656861e-05, 7.3712630073e-05, 7.3021104680e-05, 7.2303861260e-05,
 7.1560683593e-05, 7.0791358754e-05, 6.9995677204e-05, 6.9173432882e-05,
 6.8324423296e-05, 6.7448449618e-05, 6.6545316771e-05, 6.5614833521e-05,
 6.4656812572e-05, 6.3671070655e-05, 6.2657428617e-05, 6.1615711517e-05,
 6.0545748710e-05, 5.9447373943e-05, 5.8320425444e-05, 5.7164746011e-05,
 5.5980183100e-05, 5.4766588919e-05, 5.3523820512e-05, 5.2251739851e-05,
 5.0950213924e-05, 4.9619114820e-05, 4.8258319820e-05, 4.6867711482e-05,
 4.5447177727e-05, 4.3996611928e-05, 4.2515912992e-05, 4.1004985446e-05,
 3.9463739523e-05, 3.7892091243e-05, 3.6289962498e-05, 3.4657281135e-05,
 3.2993981037e-05, 3.1300002202e-05, 2.9575290828e-05, 2.7819799389e-05,
 2.6033486716e-05, 2.4216318075e-05, 2.2368265244e-05, 2.0489306587e-05,
 1.8579427136e-05, 1.6638618659e-05, 1.4666879741e-05, 1.2664215849e-05,
 1.0630639412e-05, 8.5661698866e-06, 6.4708338309e-06, 4.3446649711e-06,
 2.1877042712e-06,-4.5534510243e-20,-2.2183922032e-06,-4.4674092633e-06,
-6.7469806051e-06,-9.0570280913e-06,-1.1397465960e-05,-1.3768200765e-05,
-1.6169131315e-05,-1.8600148618e-05,-2.1061135821e-05,-2.3551968159e-05,
-2.6072512896e-05,-2.8622629274e-05,-3.1202168460e-05,-3.3810973499e-05,
-3.6448879261e-05,-3.9115712396e-05,-4.1811291283e-05,-4.4535425992e-05,
-4.7287918235e-05,-5.0068561326e-05,-5.2877140140e-05,-5.5713431075e-05,
-5.8577202010e-05,-6.1468212275e-05,-6.4386212612e-05,-6.7330945143e-05,
-7.0302143339e-05,-7.3299531988e-05,-7.6322827171e-05,-7.9371736228e-05,
-8.2445957740e-05,-8.5545181502e-05,-8.8669088501e-05,-9.1817350897e-05,
-9.4989632001e-05,-9.8185586264e-05,-1.0140485926e-04,-1.0464708766e-04,
-1.0791189924e-04,-1.1119891287e-04,-1.1450773848e-04,-1.1783797709e-04,
-1.2118922076e-04,-1.2456105265e-04,-1.2795304695e-04,-1.3136476894e-04,
-1.3479577493e-04,-1.3824561234e-04,-1.4171381965e-04,-1.4519992640e-04,
-1.4870345327e-04,-1.5222391200e-04,-1.5576080549e-04,-1.5931362774e-04,
-1.6288186392e-04,-1.6646499038e-04,-1.7006247463e-04,-1.7367377543e-04,
-1.7729834276e-04,-1.8093561787e-04,-1.8458503332e-04,-1.8824601297e-04,
-1.9191797206e-04,-1.9560031722e-04,-1.9929244651e-04,-2.0299374946e-04,
-2.0670360709e-04,-2.1042139201e-04,-2.1414646838e-04,-2.1787819205e-04,
-2.2161591052e-04,-2.2535896306e-04,-2.2910668071e-04,-2.3285838636e-04,
-2.3661339482e-04,-2.4037101285e-04,-2.4413053922e-04,-2.4789126481e-04,
-2.5165247261e-04,-2.5541343785e-04,-2.5917342803e-04,-2.6293170300e-04,
-2.6668751502e-04,-2.7044010888e-04,-2.7418872190e-04,-2.7793258406e-04,
-2.8167091807e-04,-2.8540293945e-04,-2.8912785661e-04,-2.9284487093e-04,
-2.9655317686e-04,-3.0025196200e-04,-3.0394040718e-04,-3.0761768658e-04,
-3.1128296779e-04,-3.1493541196e-04,-3.1857417383e-04,-3.2219840188e-04,
-3.2580723839e-04,-3.2939981961e-04,-3.3297527578e-04,-3.3653273132e-04,
-3.4007130486e-04,-3.4359010942e-04,-3.4708825249e-04,-3.5056483612e-04,
-3.5401895709e-04,-3.5744970699e-04,-3.6085617234e-04,-3.6423743474e-04,
-3.6759257095e-04,-3.7092065306e-04,-3.7422074856e-04,-3.7749192054e-04,
-3.8073322773e-04,-3.8394372473e-04,-3.8712246205e-04,-3.9026848631e-04,
-3.9338084034e-04,-3.9645856333e-04,-3.9950069096e-04,-4.0250625556e-04,
-4.0547428621e-04,-4.0840380894e-04,-4.1129384681e-04,-4.1414342011e-04,
-4.1695154648e-04,-4.1971724105e-04,-4.2243951663e-04,-4.2511738380e-04,
-4.2774985111e-04,-4.3033592523e-04,-4.3287461106e-04,-4.3536491195e-04,
-4.3780582981e-04,-4.4019636528e-04,-4.4253551789e-04,-4.4482228624e-04,
-4.4705566812e-04,-4.4923466071e-04,-4.5135826073e-04,-4.5342546458e-04,
-4.5543526856e-04,-4.5738666898e-04,-4.5927866237e-04,-4.6111024563e-04,
-4.6288041617e-04,-4.6458817216e-04,-4.6623251259e-04,-4.6781243755e-04,
-4.6932694833e-04,-4.7077504763e-04,-4.7215573969e-04,-4.7346803053e-04,
-4.7471092806e-04,-4.7588344231e-04,-4.7698458557e-04,-4.7801337256e-04,
-4.7896882064e-04,-4.7984994999e-04,-4.8065578373e-04,-4.8138534817e-04,
-4.8203767295e-04,-4.8261179121e-04,-4.8310673981e-04,-4.8352155947e-04,
-4.8385529498e-04,-4.8410699535e-04,-4.8427571402e-04,-4.8436050902e-04,
-4.8436044316e-04,-4.8427458423e-04,-4.8410200512e-04,-4.8384178408e-04,
-4.8349300485e-04,-4.8305475684e-04,-4.8252613535e-04,-4.8190624170e-04,
-4.8119418347e-04,-4.8038907462e-04,-4.7949003570e-04,-4.7849619404e-04,
-4.7740668391e-04,-4.7622064671e-04,-4.7493723115e-04,-4.7355559341e-04,
-4.7207489737e-04,-4.7049431471e-04,-4.6881302515e-04,-4.6703021660e-04,
-4.6514508537e-04,-4.6315683628e-04,-4.6106468290e-04,-4.5886784769e-04,
-4.5656556219e-04,-4.5415706718e-04,-4.5164161286e-04,-4.4901845903e-04,
-4.4628687524e-04,-4.4344614098e-04,-4.4049554585e-04,-4.3743438969e-04,
-4.3426198281e-04,-4.3097764611e-04,-4.2758071126e-04,-4.2407052086e-04,
-4.2044642861e-04,-4.1670779947e-04,-4.1285400982e-04,-4.0888444762e-04,
-4.0479851256e-04,-4.0059561624e-04,-3.9627518229e-04,-3.9183664658e-04,
-3.8727945730e-04,-3.8260307518e-04,-3.7780697360e-04,-3.7289063876e-04,
-3.6785356980e-04,-3.6269527899e-04,-3.5741529184e-04,-3.5201314724e-04,
-3.4648839763e-04,-3.4084060911e-04,-3.3506936162e-04,-3.2917424901e-04,
-3.2315487925e-04,-3.1701087449e-04,-3.1074187125e-04,-3.0434752054e-04,
-2.9782748793e-04,-2.9118145376e-04,-2.8440911321e-04,-2.7751017643e-04,
-2.7048436867e-04,-2.6333143040e-04,-2.5605111740e-04,-2.4864320091e-04,
-2.4110746772e-04,-2.3344372028e-04,-2.2565177682e-04,-2.1773147142e-04,
-2.0968265418e-04,-2.0150519126e-04,-1.9319896499e-04,-1.8476387399e-04,
-1.7619983325e-04,-1.6750677422e-04,-1.5868464489e-04,-1.4973340992e-04,
-1.4065305066e-04,-1.3144356528e-04,-1.2210496885e-04,-1.1263729339e-04,
-1.0304058795e-04,-9.3314918711e-05,-8.3460369032e-05,-7.3477039518e-05,
-6.3365048091e-05,-5.3124530052e-05,-4.2755638139e-05,-3.2258542586e-05,
-2.1633431179e-05,-1.0880509304e-05, 1.1310184802e-19, 1.1007855993e-05,
 2.2142800194e-05, 3.3404556336e-05, 4.4792830329e-05, 5.6307310222e-05,
 6.7947666171e-05, 7.9713550410e-05, 9.1604597220e-05, 1.0362042291e-04,
 1.1576062577e-04, 1.2802478611e-04, 1.4041246616e-04, 1.5292321014e-04,
 1.6555654419e-04, 1.7831197638e-04, 1.9118899672e-04, 2.0418707714e-04,
 2.1730567148e-04, 2.3054421553e-04, 2.4390212700e-04, 2.5737880555e-04,
 2.7097363280e-04, 2.8468597233e-04, 2.9851516972e-04, 3.1246055255e-04,
 3.2652143044e-04, 3.4069709507e-04, 3.5498682020e-04, 3.6938986172e-04,
 3.8390545768e-04, 3.9853282832e-04, 4.1327117613e-04, 4.2811968586e-04,
 4.4307752461e-04, 4.5814384185e-04, 4.7331776948e-04, 4.8859842189e-04,
 5.0398489602e-04, 5.1947627143e-04, 5.3507161034e-04, 5.5076995771e-04,
 5.6657034133e-04, 5.8247177185e-04, 5.9847324292e-04, 6.1457373120e-04,
 6.3077219650e-04, 6.4706758183e-04, 6.6345881349e-04, 6.7994480118e-04,
 6.9652443810e-04, 7.1319660100e-04, 7.2996015034e-04, 7.4681393034e-04,
 7.6375676912e-04, 7.8078747881e-04, 7.9790485563e-04, 8.1510768002e-04,
 8.3239471677e-04, 8.4976471514e-04, 8.6721640894e-04, 8.8474851671e-04,
 9.0235974182e-04, 9.2004877259e-04, 9.3781428245e-04, 9.5565493007e-04,
 9.7356935947e-04, 9.9155620020e-04, 1.0096140675e-03, 1.0277415622e-03,
 1.0459372715e-03, 1.0641997684e-03, 1.0825276121e-03, 1.1009193484e-03,
 1.1193735096e-03, 1.1378886147e-03, 1.1564631697e-03, 1.1750956677e-03,
 1.1937845887e-03, 1.2125284006e-03, 1.2313255585e-03, 1.2501745054e-03,
 1.2690736722e-03, 1.2880214780e-03, 1.3070163301e-03, 1.3260566244e-03,
 1.3451407454e-03, 1.3642670663e-03, 1.3834339497e-03, 1.4026397472e-03,
 1.4218828000e-03, 1.4411614388e-03, 1.4604739841e-03, 1.4798187468e-03,
 1.4991940276e-03, 1.5185981180e-03, 1.5380292999e-03, 1.5574858464e-03,
 1.5769660214e-03, 1.5964680802e-03, 1.6159902696e-03, 1.6355308284e-03,
 1.6550879869e-03, 1.6746599679e-03, 1.6942449865e-03, 1.7138412504e-03,
 1.7334469603e-03, 1.7530603099e-03, 1.7726794861e-03, 1.7923026695e-03,
 1.8119280344e-03, 1.8315537491e-03, 1.8511779762e-03, 1.8707988727e-03,
 1.8904145905e-03, 1.9100232762e-03, 1.9296230717e-03, 1.9492121146e-03,
 1.9687885377e-03, 1.9883504700e-03, 2.0078960369e-03, 2.0274233597e-03,
 2.0469305569e-03, 2.0664157434e-03, 2.0858770318e-03, 2.1053125316e-03,
 2.1247203504e-03, 2.1440985934e-03, 2.1634453643e-03, 2.1827587648e-03,
 2.2020368956e-03, 2.2212778563e-03, 2.2404797456e-03, 2.2596406616e-03,
 2.2787587024e-03, 2.2978319656e-03, 2.3168585495e-03, 2.3358365525e-03,
 2.3547640739e-03, 2.3736392140e-03, 2.3924600743e-03, 2.4112247579e-03,
 2.4299313695e-03, 2.4485780161e-03, 2.4671628067e-03, 2.4856838531e-03,
 2.5041392697e-03, 2.5225271742e-03, 2.5408456874e-03, 2.5590929338e-03,
 2.5772670418e-03, 2.5953661439e-03, 2.6133883768e-03, 2.6313318822e-03,
 2.6491948062e-03, 2.6669753004e-03, 2.6846715218e-03, 2.7022816329e-03,
 2.7198038022e-03, 2.7372362044e-03, 2.7545770206e-03, 2.7718244386e-03,
 2.7889766531e-03, 2.8060318661e-03, 2.8229882870e-03, 2.8398441329e-03,
 2.8565976289e-03, 2.8732470082e-03, 2.8897905125e-03, 2.9062263924e-03,
 2.9225529072e-03, 2.9387683255e-03, 2.9548709253e-03, 2.9708589945e-03,
 2.9867308307e-03, 3.0024847417e-03, 3.0181190460e-03, 3.0336320724e-03,
 3.0490221608e-03, 3.0642876623e-03, 3.0794269392e-03, 3.0944383655e-03,
 3.1093203271e-03, 3.1240712219e-03, 3.1386894602e-03, 3.1531734647e-03,
 3.1675216709e-03, 3.1817325275e-03, 3.1958044961e-03, 3.2097360520e-03,
 3.2235256839e-03, 3.2371718947e-03, 3.2506732010e-03, 3.2640281341e-03,
 3.2772352396e-03, 3.2902930778e-03, 3.3032002240e-03, 3.3159552688e-03,
 3.3285568179e-03, 3.3410034926e-03, 3.3532939302e-03, 3.3654267836e-03,
 3.3774007222e-03, 3.3892144313e-03, 3.4008666133e-03, 3.4123559869e-03,
 3.4236812877e-03, 3.4348412688e-03, 3.4458347001e-03, 3.4566603693e-03,
 3.4673170816e-03, 3.4778036599e-03, 3.4881189454e-03, 3.4982617970e-03,
 3.5082310925e-03, 3.5180257276e-03, 3.5276446170e-03, 3.5370866942e-03,
 3.5463509114e-03, 3.5554362403e-03, 3.5643416716e-03, 3.5730662154e-03,
 3.5816089016e-03, 3.5899687796e-03, 3.5981449186e-03, 3.6061364080e-03,
 3.6139423572e-03, 3.6215618958e-03, 3.6289941738e-03, 3.6362383619e-03,
 3.6432936510e-03, 3.6501592532e-03, 3.6568344011e-03, 3.6633183486e-03,
 3.6696103704e-03, 3.6757097626e-03, 3.6816158424e-03, 3.6873279485e-03,
 3.6928454411e-03, 3.6981677021e-03, 3.7032941348e-03, 3.7082241645e-03,
 3.7129572383e-03, 3.7174928251e-03, 3.7218304161e-03, 3.7259695243e-03,
 3.7299096851e-03, 3.7336504559e-03, 3.7371914165e-03, 3.7405321691e-03,
 3.7436723383e-03, 3.7466115711e-03, 3.7493495372e-03, 3.7518859286e-03,
 3.7542204602e-03, 3.7563528693e-03, 3.7582829162e-03, 3.7600103837e-03,
 3.7615350774e-03, 3.7628568257e-03, 3.7639754800e-03, 3.7648909144e-03,
 3.7656030257e-03, 3.7661117340e-03, 3.7664169818e-03, 3.7665187349e-03,
 3.7664169818e-03, 3.7661117340e-03, 3.7656030257e-03, 3.7648909144e-03,
 3.7639754800e-03, 3.7628568257e-03, 3.7615350774e-03, 3.7600103837e-03,
 3.7582829162e-03, 3.7563528693e-03, 3.7542204602e-03, 3.7518859286e-03,
 3.7493495372e-03, 3.7466115711e-03, 3.7436723383e-03, 3.7405321691e-03,
 3.7371914165e-03, 3.7336504559e-03, 3.7299096851e-03, 3.7259695243e-03,
 3.7218304161e-03, 3.7174928251e-03, 3.7129572383e-03, 3.7082241645e-03,
 3.7032941348e-03, 3.6981677021e-03, 3.6928454411e-03, 3.6873279485e-03,
 3.6816158424e-03, 3.6757097626e-03, 3.6696103704e-03, 3.6633183486e-03,
 3.6568344011e-03, 3.6501592532e-03, 3.6432936510e-03, 3.6362383619e-03,
 3.6289941738e-03, 3.6215618958e-03, 3.6139423572e-03, 3.6061364080e-03,
 3.5981449186e-03, 3.5899687796e-03, 3.5816089016e-03, 3.5730662154e-03,
 3.5643416716e-03, 3.5554362403e-03, 3.5463509114e-03, 3.5370866942e-03,
 3.5276446170e-03, 3.5180257276e-03, 3.5082310925e-03, 3.4982617970e-03,
 3.4881189454e-03, 3.4778036599e-03, 3.4673170816e-03, 3.4566603693e-03,
 3.4458347001e-03, 3.4348412688e-03, 3.4236812877e-03, 3.4123559869e-03,
 3.4008666133e-03, 3.3892144313e-03, 3.3774007222e-03, 3.3654267836e-03,
 3.3532939302e-03, 3.3410034926e-03, 3.3285568179e-03, 3.3159552688e-03,
 3.3032002240e-03, 3.2902930778e-03, 3.2772352396e-03, 3.2640281341e-03,
 3.2506732010e-03, 3.2371718947e-03, 3.2235256839e-03, 3.2097360520e-03,
 3.1958044961e-03, 3.1817325275e-03, 3.1675216709e-03, 3.1531734647e-03,
 3.1386894602e-03, 3.1240712219e-03, 3.1093203271e-03, 3.0944383655e-03,
 3.0794269392e-03, 3.0642876623e-03, 3.0490221608e-03, 3.0336320724e-03,
 3.0181190460e-03, 3.0024847417e-03, 2.9867308307e-03, 2.9708589945e-03,
 2.9548709253e-03, 2.9387683255e-03, 2.9225529072e-03, 2.9062263924e-03,
 2.8897905125e-03, 2.8732470082e-03, 2.8565976289e-03, 2.8398441329e-03,
 2.8229882870e-03, 2.8060318661e-03, 2.7889766531e-03, 2.7718244386e-03,
 2.7545770206e-03, 2.7372362044e-03, 2.7198038022e-03, 2.7022816329e-03,
 2.6846715218e-03, 2.6669753004e-03, 2.6491948062e-03, 2.6313318822e-03,
 2.6133883768e-03, 2.5953661439e-03, 2.5772670418e-03, 2.5590929338e-03,
 2.5408456874e-03, 2.5225271742e-03, 2.5041392697e-03, 2.4856838531e-03,
 2.4671628067e-03, 2.4485780161e-03, 2.4299313695e-03, 2.4112247579e-03,
 2.3924600743e-03, 2.3736392140e-03, 2.3547640739e-03, 2.3358365525e-03,
 2.3168585495e-03, 2.2978319656e-03, 2.2787587024e-03, 2.2596406616e-03,
 2.2404797456e-03, 2.2212778563e-03, 2.2020368956e-03, 2.1827587648e-03,
 2.1634453643e-03, 2.1440985934e-03, 2.1247203504e-03, 2.1053125316e-03,
 2.0858770318e-03, 2.0664157434e-03, 2.0469305569e-03, 2.0274233597e-03,
 2.0078960369e-03, 1.9883504700e-03, 1.9687885377e-03, 1.9492121146e-03,
 1.9296230717e-03, 1.9100232762e-03, 1.8904145905e-03, 1.8707988727e-03,
 1.8511779762e-03, 1.8315537491e-03, 1.8119280344e-03, 1.7923026695e-03,
 1.7726794861e-03, 1.7530603099e-03, 1.7334469603e-03, 1.7138412504e-03,
 1.6942449865e-03, 1.6746599679e-03, 1.6550879869e-03, 1.6355308284e-03,
 1.6159902696e-03, 1.5964680802e-03, 1.5769660214e-03, 1.5574858464e-03,
 1.5380292999e-03, 1.5185981180e-03, 1.4991940276e-03, 1.4798187468e-03,
 1.4604739841e-03, 1.4411614388e-03, 1.4218828000e-03, 1.4026397472e-03,
 1.3834339497e-03, 1.3642670663e-03, 1.3451407454e-03, 1.3260566244e-03,
 1.3070163301e-03, 1.2880214780e-03, 1.2690736722e-03, 1.2501745054e-03,
 1.2313255585e-03, 1.2125284006e-03, 1.1937845887e-03, 1.1750956677e-03,
 1.1564631697e-03, 1.1378886147e-03, 1.1193735096e-03, 1.1009193484e-03,
 1.0825276121e-03, 1.0641997684e-03, 1.0459372715e-03, 1.0277415622e-03,
 1.0096140675e-03, 9.9155620020e-04, 9.7356935947e-04, 9.5565493007e-04,
 9.3781428245e-04, 9.2004877259e-04, 9.0235974182e-04, 8.8474851671e-04,
 8.6721640894e-04, 8.4976471514e-04, 8.3239471677e-04, 8.1510768002e-04,
 7.9790485563e-04, 7.8078747881e-04, 7.6375676912e-04, 7.4681393034e-04,
 7.2996015034e-04, 7.1319660100e-04, 6.9652443810e-04, 6.7994480118e-04,
 6.6345881349e-04, 6.4706758183e-04, 6.3077219650e-04, 6.1457373120e-04,
 5.9847324292e-04, 5.8247177185e-04, 5.6657034133e-04, 5.5076995771e-04,
 5.3507161034e-04, 5.1947627143e-04, 5.0398489602e-04, 4.8859842189e-04,
 4.7331776948e-04, 4.5814384185e-04, 4.4307752461e-04, 4.2811968586e-04,
 4.1327117613e-04, 3.9853282832e-04, 3.8390545768e-04, 3.6938986172e-04,
 3.5498682020e-04, 3.4069709507e-04, 3.2652143044e-04, 3.1246055255e-04,
 2.9851516972e-04, 2.8468597233e-04, 2.7097363280e-04, 2.5737880555e-04,
 2.4390212700e-04, 2.3054421553e-04, 2.1730567148e-04, 2.0418707714e-04,
 1.9118899672e-04, 1.7831197638e-04, 1.6555654419e-04, 1.5292321014e-04,
 1.4041246616e-04, 1.2802478611e-04, 1.1576062577e-04, 1.0362042291e-04,
 9.1604597220e-05, 7.9713550410e-05, 6.7947666171e-05, 5.6307310222e-05,
 4.4792830329e-05, 3.3404556336e-05, 2.2142800194e-05, 1.1007855993e-05,
 1.1310184802e-19,-1.0880509304e-05,-2.1633431179e-05,-3.2258542586e-05,
-4.2755638139e-05,-5.3124530052e-05,-6.3365048091e-05,-7.3477039518e-05,
-8.3460369032e-05,-9.3314918711e-05,-1.0304058795e-04,-1.1263729339e-04,
-1.2210496885e-04,-1.3144356528e-04,-1.4065305066e-04,-1.4973340992e-04,
-1.5868464489e-04,-1.6750677422e-04,-1.7619983325e-04,-1.8476387399e-04,
-1.9319896499e-04,-2.0150519126e-04,-2.0968265418e-04,-2.1773147142e-04,
-2.2565177682e-04,-2.3344372028e-04,-2.4110746772e-04,-2.4864320091e-04,
-2.5605111740e-04,-2.6333143040e-04,-2.7048436867e-04,-2.7751017643e-04,
-2.8440911321e-04,-2.9118145376e-04,-2.9782748793e-04,-3.0434752054e-04,
-3.1074187125e-04,-3.1701087449e-04,-3.2315487925e-04,-3.2917424901e-04,
-3.3506936162e-04,-3.4084060911e-04,-3.4648839763e-04,-3.5201314724e-04,
-3.5741529184e-04,-3.6269527899e-04,-3.6785356980e-04,-3.7289063876e-04,
-3.7780697360e-04,-3.8260307518e-04,-3.8727945730e-04,-3.9183664658e-04,
-3.9627518229e-04,-4.0059561624e-04,-4.0479851256e-04,-4.0888444762e-04,
-4.1285400982e-04,-4.1670779947e-04,-4.2044642861e-04,-4.2407052086e-04,
-4.2758071126e-04,-4.3097764611e-04,-4.3426198281e-04,-4.3743438969e-04,
-4.4049554585e-04,-4.4344614098e-04,-4.4628687524e-04,-4.4901845903e-04,
-4.5164161286e-04,-4.5415706718e-04,-4.5656556219e-04,-4.5886784769e-04,
-4.6106468290e-04,-4.6315683628e-04,-4.6514508537e-04,-4.6703021660e-04,
-4.6881302515e-04,-4.7049431471e-04,-4.7207489737e-04,-4.7355559341e-04,
-4.7493723115e-04,-4.7622064671e-04,-4.7740668391e-04,-4.7849619404e-04,
-4.7949003570e-04,-4.8038907462e-04,-4.8119418347e-04,-4.8190624170e-04,
-4.8252613535e-04,-4.8305475684e-04,-4.8349300485e-04,-4.8384178408e-04,
-4.8410200512e-04,-4.8427458423e-04,-4.8436044316e-04,-4.8436050902e-04,
-4.8427571402e-04,-4.8410699535e-04,-4.8385529498e-04,-4.8352155947e-04,
-4.8310673981e-04,-4.8261179121e-04,-4.8203767295e-04,-4.8138534817e-04,
-4.8065578373e-04,-4.7984994999e-04,-4.7896882064e-04,-4.7801337256e-04,
-4.7698458557e-04,-4.7588344231e-04,-4.7471092806e-04,-4.7346803053e-04,
-4.7215573969e-04,-4.7077504763e-04,-4.6932694833e-04,-4.6781243755e-04,
-4.6623251259e-04,-4.6458817216e-04,-4.6288041617e-04,-4.6111024563e-04,
-4.5927866237e-04,-4.5738666898e-04,-4.5543526856e-04,-4.5342546458e-04,
-4.5135826073e-04,-4.4923466071e-04,-4.4705566812e-04,-4.4482228624e-04,
-4.4253551789e-04,-4.4019636528e-04,-4.3780582981e-04,-4.3536491195e-04,
-4.3287461106e-04,-4.3033592523e-04,-4.2774985111e-04,-4.2511738380e-04,
-4.2243951663e-04,-4.1971724105e-04,-4.1695154648e-04,-4.1414342011e-04,
-4.1129384681e-04,-4.0840380894e-04,-4.0547428621e-04,-4.0250625556e-04,
-3.9950069096e-04,-3.9645856333e-04,-3.9338084034e-04,-3.9026848631e-04,
-3.8712246205e-04,-3.8394372473e-04,-3.8073322773e-04,-3.7749192054e-04,
-3.7422074856e-04,-3.7092065306e-04,-3.6759257095e-04,-3.6423743474e-04,
-3.6085617234e-04,-3.5744970699e-04,-3.5401895709e-04,-3.5056483612e-04,
-3.4708825249e-04,-3.4359010942e-04,-3.4007130486e-04,-3.3653273132e-04,
-3.3297527578e-04,-3.2939981961e-04,-3.2580723839e-04,-3.2219840188e-04,
-3.1857417383e-04,-3.1493541196e-04,-3.1128296779e-04,-3.0761768658e-04,
-3.0394040718e-04,-3.0025196200e-04,-2.9655317686e-04,-2.9284487093e-04,
-2.8912785661e-04,-2.8540293945e-04,-2.8167091807e-04,-2.7793258406e-04,
-2.7418872190e-04,-2.7044010888e-04,-2.6668751502e-04,-2.6293170300e-04,
-2.5917342803e-04,-2.5541343785e-04,-2.5165247261e-04,-2.4789126481e-04,
-2.4413053922e-04,-2.4037101285e-04,-2.3661339482e-04,-2.3285838636e-04,
-2.2910668071e-04,-2.2535896306e-04,-2.2161591052e-04,-2.1787819205e-04,
-2.1414646838e-04,-2.1042139201e-04,-2.0670360709e-04,-2.0299374946e-04,
-1.9929244651e-04,-1.9560031722e-04,-1.9191797206e-04,-1.8824601297e-04,
-1.8458503332e-04,-1.8093561787e-04,-1.7729834276e-04,-1.7367377543e-04,
-1.7006247463e-04,-1.6646499038e-04,-1.6288186392e-04,-1.5931362774e-04,
-1.5576080549e-04,-1.5222391200e-04,-1.4870345327e-04,-1.4519992640e-04,
-1.4171381965e-04,-1.3824561234e-04,-1.3479577493e-04,-1.3136476894e-04,
-1.2795304695e-04,-1.2456105265e-04,-1.2118922076e-04,-1.1783797709e-04,
-1.1450773848e-04,-1.1119891287e-04,-1.0791189924e-04,-1.0464708766e-04,
-1.0140485926e-04,-9.8185586264e-05,-9.4989632001e-05,-9.1817350897e-05,
-8.8669088501e-05,-8.5545181502e-05,-8.2445957740e-05,-7.9371736228e-05,
-7.6322827171e-05,-7.3299531988e-05,-7.0302143339e-05,-6.7330945143e-05,
-6.4386212612e-05,-6.1468212275e-05,-5.8577202010e-05,-5.5713431075e-05,
-5.2877140140e-05,-5.0068561326e-05,-4.7287918235e-05,-4.4535425992e-05,
-4.1811291283e-05,-3.9115712396e-05,-3.6448879261e-05,-3.3810973499e-05,
-3.1202168460e-05,-2.8622629274e-05,-2.6072512896e-05,-2.3551968159e-05,
-2.1061135821e-05,-1.8600148618e-05,-1.6169131315e-05,-1.3768200765e-05,
-1.1397465960e-05,-9.0570280913e-06,-6.7469806051e-06,-4.4674092633e-06,
-2.2183922032e-06,-4.5534510243e-20, 2.1877042712e-06, 4.3446649711e-06,
 6.4708338309e-06, 8.5661698866e-06, 1.0630639412e-05, 1.2664215849e-05,
 1.4666879741e-05, 1.6638618659e-05, 1.8579427136e-05, 2.0489306587e-05,
 2.2368265244e-05, 2.4216318075e-05, 2.6033486716e-05, 2.7819799389e-05,
 2.9575290828e-05, 3.1300002202e-05, 3.2993981037e-05, 3.4657281135e-05,
 3.6289962498e-05, 3.7892091243e-05, 3.9463739523e-05, 4.1004985446e-05,
 4.2515912992e-05, 4.3996611928e-05, 4.5447177727e-05, 4.6867711482e-05,
 4.8258319820e-05, 4.9619114820e-05, 5.0950213924e-05, 5.2251739851e-05,
 5.3523820512e-05, 5.4766588919e-05, 5.5980183100e-05, 5.7164746011e-05,
 5.8320425444e-05, 5.9447373943e-05, 6.0545748710e-05, 6.1615711517e-05,
 6.2657428617e-05, 6.3671070655e-05, 6.4656812572e-05, 6.5614833521e-05,
 6.6545316771e-05, 6.7448449618e-05, 6.8324423296e-05, 6.9173432882e-05,
 6.9995677204e-05, 7.0791358754e-05, 7.1560683593e-05, 7.2303861260e-05,
 7.3021104680e-05, 7.3712630073e-05, 7.4378656861e-05, 7.5019407579e-05,
 7.5635107781e-05, 7.6225985948e-05, 7.6792273401e-05, 7.7334204203e-05,
 7.7852015075e-05, 7.8345945299e-05, 7.8816236631e-05, 7.9263133209e-05,
 7.9686881464e-05, 8.0087730028e-05, 8.0465929646e-05, 8.0821733085e-05,
 8.1155395046e-05, 8.1467172075e-05, 8.1757322474e-05, 8.2026106214e-05,
 8.2273784846e-05, 8.2500621413e-05, 8.2706880366e-05, 8.2892827475e-05,
 8.3058729744e-05, 8.3204855326e-05, 8.3331473436e-05, 8.3438854270e-05,
 8.3527268917e-05, 8.3596989278e-05, 8.3648287984e-05, 8.3681438312e-05,
 8.3696714102e-05, 8.3694389682e-05, 8.3674739779e-05, 8.3638039448e-05,
 8.3584563985e-05, 8.3514588856e-05, 8.3428389614e-05, 8.3326241823e-05,
 8.3208420983e-05, 8.3075202457e-05, 8.2926861388e-05, 8.2763672636e-05,
 8.2585910696e-05, 8.2393849628e-05, 8.2187762990e-05, 8.1967923761e-05,
 8.1734604273e-05, 8.1488076144e-05, 8.1228610209e-05, 8.0956476450e-05,
 8.0671943934e-05, 8.0375280743e-05, 8.0066753913e-05, 7.9746629367e-05,
 7.9415171857e-05, 7.9072644894e-05, 7.8719310698e-05, 7.8355430128e-05,
 7.7981262629e-05, 7.7597066172e-05, 7.7203097196e-05, 7.6799610555e-05,
 7.6386859459e-05, 7.5965095424e-05, 7.5534568215e-05, 7.5095525799e-05,
 7.4648214288e-05, 7.4192877893e-05, 7.3729758875e-05, 7.3259097496e-05,
 7.2781131971e-05, 7.2296098428e-05, 7.1804230854e-05, 7.1305761060e-05,
 7.0800918635e-05, 7.0289930903e-05, 6.9773022885e-05, 6.9250417260e-05,
 6.8722334323e-05, 6.8188991955e-05, 6.7650605579e-05, 6.7107388130e-05,
 6.6559550021e-05, 6.6007299107e-05, 6.5450840659e-05, 6.4890377328e-05,
 6.4326109118e-05, 6.3758233357e-05, 6.3186944673e-05, 6.2612434961e-05,
 6.2034893367e-05, 6.1454506256e-05, 6.0871457195e-05, 6.0285926926e-05,
 5.9698093353e-05, 5.9108131514e-05, 5.8516213569e-05, 5.7922508779e-05,
 5.7327183494e-05, 5.6730401131e-05, 5.6132322167e-05, 5.5533104125e-05,
 5.4932901556e-05, 5.4331866037e-05, 5.3730146156e-05, 5.3127887502e-05,
 5.2525232664e-05, 5.1922321217e-05, 5.1319289724e-05, 5.0716271725e-05,
 5.0113397738e-05, 4.9510795252e-05, 4.8908588735e-05, 4.8306899622e-05,
 4.7705846324e-05, 4.7105544228e-05, 4.6506105698e-05, 4.5907640081e-05,
 4.5310253710e-05, 4.4714049910e-05, 4.4119129007e-05, 4.3525588332e-05,
 4.2933522235e-05, 4.2343022087e-05, 4.1754176299e-05, 4.1167070327e-05,
 4.0581786687e-05, 3.9998404969e-05, 3.9417001850e-05, 3.8837651110e-05,
 3.8260423646e-05, 3.7685387493e-05, 3.7112607836e-05, 3.6542147034e-05,
 3.5974064636e-05, 3.5408417403e-05, 3.4845259328e-05, 3.4284641659e-05,
 3.3726612919e-05, 3.3171218934e-05, 3.2618502852e-05, 3.2068505173e-05,
 3.1521263770e-05, 3.0976813919e-05, 3.0435188325e-05, 2.9896417149e-05,
 2.9360528038e-05, 2.8827546152e-05, 2.8297494197e-05, 2.7770392453e-05,
 2.7246258806e-05, 2.6725108782e-05, 2.6206955574e-05, 2.5691810082e-05,
 2.5179680941e-05, 2.4670574556e-05, 2.4164495141e-05, 2.3661444750e-05,
 2.3161423314e-05, 2.2664428676e-05, 2.2170456632e-05, 2.1679500965e-05,
 2.1191553481e-05, 2.0706604052e-05, 2.0224640651e-05, 1.9745649395e-05,
 1.9269614578e-05, 1.8796518718e-05, 1.8326342592e-05, 1.7859065281e-05,
 1.7394664207e-05, 1.6933115176e-05, 1.6474392423e-05, 1.6018468647e-05,
 1.5565315058e-05, 1.5114901421e-05, 1.4667196094e-05, 1.4222166074e-05,
 1.3779777040e-05, 1.3339993396e-05, 1.2902778316e-05, 1.2468093785e-05,
 1.2035900647e-05, 1.1606158644e-05, 1.1178826466e-05, 1.0753861792e-05,
 1.0331221334e-05, 9.9108608857e-06, 9.4927353615e-06, 9.0767988460e-06,
 8.6630046363e-06, 8.2513052879e-06, 7.8416526592e-06, 7.4339979562e-06,
 7.0282917779e-06, 6.6244841603e-06, 6.2225246219e-06, 5.8223622081e-06,
 5.4239455359e-06, 5.0272228381e-06, 4.6321420085e-06, 4.2386506453e-06,
 3.8466960961e-06, 3.4562255014e-06, 3.0671858386e-06, 2.6795239658e-06,
 2.2931866654e-06, 1.9081206871e-06, 1.5242727912e-06, 1.1415897914e-06,
 7.6001859743e-07, 3.7950625746e-07, 0.0
};