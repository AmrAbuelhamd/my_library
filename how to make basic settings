import androidx.appcompat.app.AppCompatActivity;
import androidx.preference.PreferenceFragmentCompat;

public class SettingsActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportFragmentManager().beginTransaction()
                .replace(android.R.id.content, new EarthquakePreferenceFragment())
                .commit();
        //The code above uses the typical pattern for adding a fragment to an activity
        // so that the fragment appears as the main content of the activity:


    }


    public static class EarthquakePreferenceFragment extends PreferenceFragmentCompat {
        @Override
        public void onCreatePreferences(Bundle savedInstanceState, String rootKey) {
            setPreferencesFromResource(R.xml.settings_main, rootKey);
        }
    }
}
*** this is how to retreieve data from anywhere in the app ***
SharedPreferences sharedPref =
                android.support.v7.preference.PreferenceManager
                        .getDefaultSharedPreferences(this);
        Boolean switchPref = sharedPref.getBoolean
                (SettingsActivity.KEY_PREF_EXAMPLE_SWITCH, false);
        Toast.makeText(this, switchPref.toString(),
                Toast.LENGTH_SHORT).show();
          ---------------------------------------------------------------------------------------------      
                
*** this is the xml file *** HINT contains very important feature noted down there
<?xml version="1.0" encoding="utf-8"?>
<PreferenceScreen xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    android:title="@string/settings_title">
    <ListPreference
        android:defaultValue="@string/settings_order_by_default"
        android:entries="@array/settings_order_by_labels"
        android:entryValues="@array/settings_order_by_values"
        android:key="@string/settings_order_by_key"
        android:title="@string/settings_order_by_label"
        app:useSimpleSummaryProvider="true"/>

    <EditTextPreference
        android:defaultValue="@string/settings_min_magnitude_default"
        android:inputType="numberDecimal"
        android:key="@string/settings_min_magnitude_key"
        android:selectAllOnFocus="true"
        android:title="@string/settings_min_magnitude_label"
        app:useSimpleSummaryProvider="true"/>
    <EditTextPreference
        android:defaultValue="10"
        android:inputType="numberDecimal"
        android:key="@string/settings_min_results_key"
        android:selectAllOnFocus="true"
        android:title="@string/settings_min_results_label"
        app:useSimpleSummaryProvider="true"/> /*** this is very important to update the summary automatically***

</PreferenceScreen>
-----------------------------------------
aarray file 
<?xml version="1.0" encoding="utf-8"?>
<resources>
    <string-array name="settings_order_by_labels">
        <item>@string/settings_order_by_magnitude_label</item>
        <item>@string/settings_order_by_most_recent_label</item>
    </string-array>

    <string-array name="settings_order_by_values">
        <item>@string/settings_order_by_magnitude_value</item>
        <item>@string/settings_order_by_most_recent_value</item>
    </string-array>
</resources>




// i should import this 

    implementation 'androidx.preference:preference:1.1.0-rc01'
