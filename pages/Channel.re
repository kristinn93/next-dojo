[@react.component]
let make = (~name, ~endpoint) => {
  let name: option(string) = Js.Nullable.toOption(name);
  let endpoint: option(string) = Js.Nullable.toOption(endpoint);
  switch (name, endpoint) {
  | (Some(name), Some(endpoint)) =>
    <p>
      {ReasonReact.string("Welcome to " ++ name ++ " endpoint: " ++ endpoint)}
    </p>
  | _ => <p />
  };
};

let getInitialProps = context => {
  let name = context##query##name;
  let endpoint = context##query##endpoint;
  {"name": name, "endpoint": endpoint};
};

Next.inject(make, getInitialProps);

let default = make;
