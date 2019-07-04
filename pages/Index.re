[@react.component]
let make = (~data) => {
  let parsedResponse = Types.TvDecoder.decodeTvChannels(data);
  switch (parsedResponse) {
  | Some(tvChannels) =>
    <div>
      {ReasonReact.string(tvChannels.info)}
      <div>
        <ul>
          {tvChannels.channels
           ->Belt.Array.map(channel =>
               <li key={channel.endpoint}>
                 <Next.Link
                   href={
                     "/Channel?name="
                     ++ channel.name
                     ++ "&endpoint="
                     ++ channel.endpoint
                   }>
                   <p> {ReasonReact.string(channel.name)} </p>
                 </Next.Link>
               </li>
             )
           ->ReasonReact.array}
        </ul>
      </div>
    </div>
  | None => <div> <p> {ReasonReact.string("No info found")} </p> </div>
  };
};

let getInitialProps = _context => {
  Js.Promise.(
    Fetcher.getTvChannels
    |> then_(json => {
         Js.log(json);
         resolve({"data": json});
       })
  );
};

Next.inject(make, getInitialProps);

let default = make;
