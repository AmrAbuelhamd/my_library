
import android.content.SharedPreferences;
import android.graphics.drawable.ColorDrawable;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private SharedPreferences mPreferences; // ***an object for SharedPreference***
    private String sharedPrefFile = "com.example.android.hellosharedprefs"; // ***a name for the permenent file that will be saved on the user phone ***

    // Current count
    private int mCount = 0;
    // Current background color
    private int mColor;
    // Text view to display both count and color
    private TextView mShowCountTextView;

    // Key for current count
    private final String COUNT_KEY = "count";
    // Key for current color
    private final String COLOR_KEY = "color";

    // *** and i retrieve my data here in on create ***
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Initialize views, color
        mShowCountTextView = findViewById(R.id.count_textview);
        mColor = ContextCompat.getColor(this,
                R.color.default_background);

        mPreferences = getSharedPreferences(sharedPrefFile, MODE_PRIVATE); *** inistalize the shared preferences file ***

        // *** Restoring date from the sharedPreferences. ***
        mCount = mPreferences.getInt(COUNT_KEY, 0); 
        mShowCountTextView.setText(String.format("%s", mCount));
        mColor = mPreferences.getInt(COLOR_KEY, mColor);
        mShowCountTextView.setBackgroundColor(mColor);
    }

    /**
     * Handles the onClick for the background color buttons. Gets background
     * color of the button that was clicked, and sets the TextView background
     * to that color.
     *
     * @param view The view (Button) that was clicked.
     */
    public void changeBackground(View view) {
        int color = ((ColorDrawable) view.getBackground()).getColor();
        mShowCountTextView.setBackgroundColor(color);
        mColor = color;
    }

    /**
     * Handles the onClick for the Count button. Increments the value of the
     * mCount global and updates the TextView.
     *
     * @param view The view (Button) that was clicked.
     */
    public void countUp(View view) {
        mCount++;
        mShowCountTextView.setText(String.format("%s", mCount));
    }


    /**
     * Handles the onClick for the Reset button. Resets the global count and
     * background variables to the defaults and resets the views to those
     * default values.
     *
     * @param view The view (Button) that was clicked.
     */
    public void reset(View view) {
        // Reset count
        mCount = 0;
        mShowCountTextView.setText(String.format("%s", mCount));

        // Reset color
        mColor = ContextCompat.getColor(this,
                R.color.default_background);
        mShowCountTextView.setBackgroundColor(mColor);

        // *** Clear preferences ***
        SharedPreferences.Editor preferencesEditor = mPreferences.edit();
        preferencesEditor.clear();
        preferencesEditor.apply();

    }

    // *** i should pay close attention that i a copy of my data on the on pause callback***
    @Override
    protected void onPause(){
        super.onPause();
      *** should get sharedpreferences Editor object to **EDIT** my shared preferences file ***
        SharedPreferences.Editor preferencesEditor = mPreferences.edit(); 

        preferencesEditor.putInt(COUNT_KEY, mCount);
        preferencesEditor.putInt(COLOR_KEY, mColor);

        preferencesEditor.apply();
    }
}
