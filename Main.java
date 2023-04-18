package il2cpp;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.os.Build;
import android.os.Handler;
import android.text.Html;
import android.view.Gravity;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;
import il2cpp.typefaces.*;
import il2cpp.typefaces.CheckBox;

public class Main {
	protected static Context context;
	
	public static native void Changes(int feature, int value);
    public static native String[] getFeatures();
	
	public static void start(final Context context) {
		Main.context = context;
		if (Build.VERSION.SDK_INT >= 23) {
			if (context.checkSelfPermission(Manifest.permission.READ_EXTERNAL_STORAGE) == PackageManager.PERMISSION_DENIED
				|| context.checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_DENIED) {
				((Activity) context).requestPermissions(new String[] {Manifest.permission.READ_EXTERNAL_STORAGE, Manifest.permission.WRITE_EXTERNAL_STORAGE}, 1000);
				init(context);
			}
			else {
				init(context);
			}
		}
		else {
			init(context);
		}
	}

	public static void init(final Context context) {
		Handler handler = new Handler();
		handler.postDelayed(new Runnable() {
				@Override
				public void run() {
					System.loadLibrary("gvraudio");
					
					try {
						new Main().MenuMain(context);
					} catch(Exception e) {
						Toast.makeText(context, e.toString(), Toast.LENGTH_LONG).show();
					}
				}
			}, 3000);
	}
	public Integer parseInt(String tok) {
        return Integer.parseInt(tok);
	}
	public final void MenuMain(final Context context) {
        
		Main.context = context;
		Menu menu = new Menu(context);
		
		String[] ft = getFeatures();
		for (String token: ft) {
			final String[] split = token.split("_");
			
			if (split[0].equals("page")) {
				menu.newPage(split[1]);
			}
            if (split[0].equals("BLOCK")) {
                menu.newBlock(Integer.parseInt(split[1]), split[2].split(","));
			}
            if (split[0].equals("SLIDER")) {
				menu.newSlider(Integer.parseInt(split[1]), split[3], Integer.parseInt(split[4]), Integer.parseInt(split[5]), new WeaveSeekBar.Callback() {
						public void onChange(int v) {
							Changes(Integer.parseInt(split[2]), v);
						}
					});
			}
			switch (split[0]) {
				case "switch":
					CheckBox button = new CheckBox(context);
					button.setText(split[3]);
					button.setCallback(new CheckBox.Callback() {
						public void onChanged(boolean check) {
							Changes(Integer.parseInt(split[2]), check ? 1 : 0);
						}
                        
					});
					menu.blocks.get(Integer.parseInt(split[1])).main.addView(button);
                    
			}
		}
		
	}
	
}

