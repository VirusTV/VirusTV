#include <pthread.h>
#include <jni.h>
#include <Includes/Utils.h>

extern "C" {

/*Time For Bools And all*/

const char *libName = "libil2cpp.so";

JNIEXPORT jstring JNICALL
Java_il2cpp_typefaces_Menu_reneim(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF("tenmi free 0.19.3");
}
JNIEXPORT jobjectArray  JNICALL Java_il2cpp_Main_getFeatures(JNIEnv *env, jobject activityObject) {
	jobjectArray ret;
	// switch_featureid_text
	// page_text
	const char *features[] = {
		"page_Player",
		"page_Esp",
		"page_Misc",
        "page_Skins",
        
        
        "BLOCK_0_AimBot,Visuals", // 0,1
        "BLOCK_1_Esp,Settenings", // 2,3
        "BLOCK_2_Misc", // 4
        "BLOCK_3_Skins",//5
        
        //aim
		"switch_0_1_enebled",
		"switch_0_2_Aim",
		"switch_0_3_Check",
        "switch_0_4_Silent Aim",
	    "SLIDER_0_208_FOV_360_0",//3
        "switch_0_5_enebled",
		//visuals
        "switch_1_1_enebled",
        "switch_1_2_Wareframe",
        "switch_1_3_Glow",
        "switch_1_4_Rainbow",
        "switch_1_5_Chams",
        "switch_1_6_Color",
        "switch_1_7_Deafolt",
        "SLIDER_1_8_R_360_0",//3
        "SLIDER_1_9_G_360_0",//3
        "SLIDER_1_10_B_360_0",//
        "SLIDER_1_11_Line Whid_360_0",//3
        //esp
        "switch_2_1_Esp",
        "switch_2_2_Box",
        "switch_2_5_Esp Nick",
        "switch_2_6_3D Esp",
        "switch_2_7_2D Esp",
        "switch_2_8_enebled",
        "switch_2_9_Team Esp",
        //sett
        "SLIDER_3_1_Color R_360_0",//3
        "SLIDER_3_2_Color G_360_0",//3
        "SLIDER_3_3_Color B_360_0",//3
        "SLIDER_3_4_Box Corner_2_1",//3
        "SLIDER_3_5_Line Whid_360_0",//3
        //player
        "switch_4_1_Fov",
        "switch_4_2_GodeMode(fix)",
        "switch_4_3_Drop Knife(fix)",
        "switch_4_4_Trigger Bot",
        "switch_4_5_Air jump",
        "switch_4_6_Speed Hack",
        "switch_4_7_Rapid Fire",
        "switch_4_8_Norecoil On",
        "switch_4_9_Norecoil 25%",
        "switch_4_10_Norecoil 50%",
        "switch_4_11_Norecoil 75%",
        "switch_4_12_Norecoil 100%",
        "switch_4_13_Norecoil Off",
        //skins//
        "switch_5_1_M9 Dragon Glass",
        "switch_5_2_M9 Skratch",
        "switch_5_3_M9 Universe",
        "switch_5_4_M9 Frozen",
        "switch_5_5_M9 Kumo",
        "switch_5_6_Karambit Dragon Glass",
        "switch_5_7_Karambit Skratch",
        "switch_5_8_Karambit Universe",
        "switch_5_9_Karambit Frozen",
        "switch_5_10_Karambit Kumo",
        "switch_5_11_Jkomando Lucshery",
        "switch_5_12_Deafolt Knife",
        "switch_5_13_Deafolt M9",
        "switch_5_14_Deafolt Karambit",
        "switch_5_15_Deafolt Jkomando",
	};
	int Total_Feature = (sizeof features /
						 sizeof features[0]); //Now you dont have to manually update the number everytime;
	
	ret = (jobjectArray) env->NewObjectArray(Total_Feature, env->FindClass("java/lang/String"), env->NewStringUTF(""));
	int i;
	for (i = 0; i < Total_Feature; i++)
		env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));
	return (ret);
}

JNIEXPORT void JNICALL
Java_il2cpp_Main_Changes(JNIEnv *env,jobject activityObject,jint feature,jint value) {
	/*  FEATURES  */
	switch (feature) {
		
	}
}

// EXTERN END
}

// ---------- Hooking ---------- //

void *hack_thread(void *) {
	
	
	
    // ---------- Hook ---------- //
	
    return NULL;
}

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *globalEnv;
    vm->GetEnv((void **) &globalEnv, JNI_VERSION_1_6);

    // Create a new thread so it does not block the main thread, means the game would not freeze
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);

    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL
JNI_OnUnload(JavaVM *vm, void *reserved) {}
