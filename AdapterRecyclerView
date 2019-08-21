package com.example.android.quakereport;

import android.content.Context;
import android.content.Intent;
import android.graphics.drawable.GradientDrawable;
import android.net.Uri;
import android.support.v4.content.ContextCompat;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.time.Instant;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.ZoneId;
import java.time.format.DateTimeFormatter;
import java.util.Date;
import java.util.List;

// manage the whole list items and and create the required views
    // and bind the timeInMilliseconds to their views
public class EarthQuakeAdapter extends RecyclerView.Adapter<EarthQuakeAdapter.MyViewHolder> {


    private static Context context;
    private List<Earthquake> mEarthquakes;
    private static final String LOCATION_SEPARATOR = " of ";
 
    // Provide a suitable constructor (depends on the kind of dataset)
    public EarthQuakeAdapter(List<Earthquake> earthquakes, Context context) {
        mEarthquakes = earthquakes;
        this.context = context;
    }

    //**define the view item in your list, get the objects from the xml,
    // Provide a reference to the views for each timeInMilliseconds item
    // Complex timeInMilliseconds items may need more than one view per item, and
    // you provide access to all the views for a timeInMilliseconds item in a view holder
    // each timeInMilliseconds item is just a string in this case
    public static class MyViewHolder extends RecyclerView.ViewHolder {
        public TextView magnitudeTV;
        public TextView dateTV;
        public TextView timeTV;
        public TextView smallLocationTV;
        public TextView bigLocationTV;

        public MyViewHolder(View itemView) {
            super(itemView);

            magnitudeTV = itemView.findViewById(R.id.magnitude);
            dateTV = itemView.findViewById(R.id.date);
            timeTV = itemView.findViewById(R.id.time);
            smallLocationTV = itemView.findViewById(R.id.small_location_tv);
            bigLocationTV = itemView.findViewById(R.id.big_location_tv);
        }

        public void bind(final String earthquakeUrl) {
            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse(earthquakeUrl));
                    context.startActivity(browserIntent);
                }
            });
        }
    }


    // Create new views (invoked by the layout manager)
    @Override
    public EarthQuakeAdapter.MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        //create new view
        Context context = parent.getContext();
        LayoutInflater inflater = LayoutInflater.from(context);

        // Inflate the custom layout
        View earthQuakView = inflater.inflate(R.layout.item_earthquake, parent, false);

        // Return a new holder instance
        MyViewHolder viewHolder = new MyViewHolder(earthQuakView);
        return viewHolder;
    }

    // Replace the contents of a view (invoked by the layout manager)
    @Override
    public void onBindViewHolder(MyViewHolder holder, int position) {


        Earthquake earthquake = mEarthquakes.get(position);
        // - get element from your dataset at this position
        // - replace the contents of the view with that element



        holder.magnitudeTV.setText(formatMagnitude(earthquake.getmMagnitude()));

        // Set the proper background color on the magnitude circle.
        // Fetch the background from the TextView, which is a GradientDrawable.
        GradientDrawable magnitudeCircle = (GradientDrawable) holder.magnitudeTV.getBackground();

        // Get the appropriate background color based on the current earthquake magnitude
        int magnitudeColor = getMagnitudeColor(earthquake.getmMagnitude());

       


        // getting date from @Earthqueke
        long unixTime = earthquake.getTimeInMilliseconds();

        holder.timeTV.setText(getFormatedTime(unixTime));
        holder.dateTV.setText(getFormatedDate(unixTime));

        //getting location from @earthquake and split it to two text
        String location = earthquake.getmLocation();
        if (location.contains(LOCATION_SEPARATOR)){
            String[] splittedText = location.split("(?<=of )"); //retain the split character
            // in the resulting parts, then make use of positive lookaround. https://www.regular-expressions.info/lookaround.html
            holder.smallLocationTV.setText(splittedText[0]);
            holder.bigLocationTV.setText(splittedText[1]);
        }else {
            holder.smallLocationTV.setText((R.string.near_the));
            holder.bigLocationTV.setText(location);
        }
        //trying to make kistener
        holder.bind(earthquake.getUrl());
    }

   

    /**
     * Return the formatted magnitude string showing 1 decimal place (i.e. "3.2")
     * from a decimal magnitude value.
     */
    private String formatMagnitude(double magnitude) {
        DecimalFormat magnitudeFormat = new DecimalFormat("0.0");
        return magnitudeFormat.format(magnitude);
    }
    //region formatting human readable date
    private String getFormatedDate(long unixTime) {
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {

            Instant instant = Instant.ofEpochMilli(unixTime);
            LocalDateTime localDateTime = LocalDateTime.ofInstant(instant, ZoneId.systemDefault());
            LocalDate localDate = localDateTime.toLocalDate();

            return localDate.format(DateTimeFormatter.ofPattern("LLL dd, yyyy"));
        }
            Date date = new Date(unixTime);
        SimpleDateFormat dateFormatter = new SimpleDateFormat("LLL dd, yyyy");

        return dateFormatter.format(date);
    }
// CHANGE THE TIME FROM UNIX LONG NUMVERS TO HUMAN REDABLE FORMAT
    private String getFormatedTime(long unixTime) {
    //this omly works with android oreo or above, SO I AM CHECKING WICH ANDROID USER HAS
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {
            Instant instant = Instant.ofEpochMilli(unixTime);
            LocalDateTime localDateTime = LocalDateTime.ofInstant(instant, ZoneId.systemDefault());
            LocalTime localTime = localDateTime.toLocalTime();

            return localTime.format(DateTimeFormatter.ofPattern("h:mm a"));
        }
        // THIS WORKS WITH EVERY ANDROID 
        Date date = new Date(unixTime);
        SimpleDateFormat dateFormatter = new SimpleDateFormat("h:mm a");

        return dateFormatter.format(date);
    }
    //endregion

    // Return the size of your dataset (invoked by the layout manager)
    @Override
    public int getItemCount() {
        return mEarthquakes.size();
    }
}
